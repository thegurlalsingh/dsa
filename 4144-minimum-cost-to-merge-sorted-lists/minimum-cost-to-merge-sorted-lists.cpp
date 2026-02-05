class Solution {
    int n;
    vector<int> len, med;
    vector<long long> memo;

    long long solve(int mask) {
        // single list → no cost
        if ((mask & (mask - 1)) == 0)
            return 0;

        long long &res = memo[mask];
        if (res != -1) return res;

        res = LLONG_MAX;

        int lb = mask & -mask;  // lowest set bit

        for (int sub = (mask - 1) & mask; sub; sub = (sub - 1) & mask) {
            if (!(sub & lb)) continue;   // avoid duplicate partitions

            int other = mask ^ sub;

            long long cost =
                solve(sub) +
                solve(other) +
                len[sub] + len[other] +
                llabs((long long)med[sub] - med[other]);

            res = min(res, cost);
        }
        return res;
    }

public:
    long long minMergeCost(vector<vector<int>>& lists) {
        n = lists.size();
        int N = 1 << n;

        len.resize(N);
        med.resize(N);
        memo.assign(N, -1);

        vector<vector<int>> merged(N);

        // base masks
        for (int i = 0; i < n; i++) {
            int m = 1 << i;
            merged[m] = lists[i];
            len[m] = lists[i].size();
            med[m] = lists[i][(lists[i].size() - 1) / 2];
        }

        // build merged info for all masks
        for (int mask = 1; mask < N; mask++) {
            if ((mask & (mask - 1)) == 0) continue;

            int lb = mask & -mask;
            int rest = mask ^ lb;

            merged[mask].resize(merged[lb].size() + merged[rest].size());
            merge(
                merged[lb].begin(), merged[lb].end(),
                merged[rest].begin(), merged[rest].end(),
                merged[mask].begin()
            );

            len[mask] = merged[mask].size();
            med[mask] = merged[mask][(len[mask] - 1) / 2];
        }

        return solve(N - 1);
    }
};
