class Solution {
    int n;
    vector<long long> dp;
    vector<long long> best;

    int bs(int i, vector<vector<int>>& a) {
        int target = a[i][1];

        int l = i + 1;
        int r = n - 1;
        int ans = n;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (a[mid][0] >= target) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    // best[i] = max(start[j] + dp[j]) for j >= i
    long long getBest(int i, vector<vector<int>>& a) {
        if (i == n){
            return 0;
        }

        if (best[i] != -1){
            return best[i];
        }

        long long cur = a[i][0] + solve(i, a);

        return best[i] = max(cur, getBest(i + 1, a));
    }

    // dp[i] = best earnings when i is selected
    long long solve(int i, vector<vector<int>>& a) {
        if (i == n){
            return 0;
        }

        if (dp[i] != -1){
            return dp[i];
        }

        long long take = a[i][2];

        int next = bs(i, a);

        if (next < n) {
            take = max(take, (long long)a[i][2] - a[i][1] + getBest(next, a));
        }

        return dp[i] = take;
    }

public:
    long long maxEarnings(vector<vector<int>>& a) {
        sort(a.begin(), a.end());

        n = a.size();

        dp.assign(n, -1);
        best.assign(n + 1, -1);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, solve(i, a));
        }

        return ans;
    }
};