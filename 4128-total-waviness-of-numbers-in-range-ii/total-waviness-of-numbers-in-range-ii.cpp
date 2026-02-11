class Solution {
    string S;

    // [idx][prev][pprev][tight][leading_zero]
    pair<long long, long long> memo[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    pair<long long, long long> dp(int idx, int prev, int pprev,
                                  bool tight, bool leading_zeros) {

        if (idx == S.size()) {
            return {1, 0};  // {count, sum}
        }

        if (vis[idx][prev][pprev][tight][leading_zeros])
            return memo[idx][prev][pprev][tight][leading_zeros];

        long long total_count = 0;
        long long total_sum = 0;

        int limit = tight ? (S[idx] - '0') : 9;

        for (int digit = 0; digit <= limit; digit++) {

            bool next_tight = tight && (digit == limit);
            bool next_lz = leading_zeros && (digit == 0);

            int next_prev = next_lz ? 10 : digit;
            int next_pprev = next_lz ? 10 : prev;

            auto [sub_count, sub_sum] =
                dp(idx + 1, next_prev, next_pprev, next_tight, next_lz);

            total_count += sub_count;
            total_sum += sub_sum;

            // Check peak/valley
            if (!leading_zeros && prev != 10 && pprev != 10) {
                bool isPeak = (prev > pprev && prev > digit);
                bool isValley = (prev < pprev && prev < digit);

                if (isPeak || isValley)
                    total_sum += sub_count;
            }
        }

        vis[idx][prev][pprev][tight][leading_zeros] = true;
        return memo[idx][prev][pprev][tight][leading_zeros] =
               {total_count, total_sum};
    }

    long long solve(string s) {
        S = s;
        memset(vis, 0, sizeof(vis));
        return dp(0, 10, 10, true, true).second;
    }

public:
    long long totalWaviness(long long num1, long long num2) {
        return solve(to_string(num2)) -
               solve(to_string(num1 - 1));
    }
};
