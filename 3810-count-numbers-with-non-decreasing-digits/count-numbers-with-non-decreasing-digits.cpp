const int MOD = 1e9 + 7;

class Solution {
    int dp[350][2][11];

    int solve(int pos, int tight, int prev, string& s, int b) {
        if (pos == s.size()) {
            return (prev != -1); // started
        }

        int p = (prev == -1 ? 10 : prev);

        if (dp[pos][tight][p] != -1)
            return dp[pos][tight][p];

        long long res = 0;
        int limit = (tight ? s[pos] - '0' : b - 1);

        for (int dig = 0; dig <= limit; dig++) {
            int new_tight = (tight && (dig == limit));

            // enforce non-decreasing
            if (prev != -1 && dig < prev)
                continue;

            int new_prev = prev;
            if (prev != -1 || dig != 0)
                new_prev = dig;

            res = (res + solve(pos + 1, new_tight, new_prev, s, b)) % MOD;
        }

        return dp[pos][tight][p] = (int)res;
    }

    string divide(string num, int b, int& rem) {
        string res = "";
        long long cur = 0;
        for (char c : num) {
            cur = cur * 10 + (c - '0');
            if (!res.empty() || cur / b > 0)
                res += (cur / b) + '0';
            cur %= b;
        }
        rem = cur;
        return res.empty() ? "0" : res;
    }

    string toBase(string num, int b) {
        if (num == "0")
            return "0";

        string res = "";
        while (num != "0") {
            int rem;
            num = divide(num, b, rem);
            if (rem < 10)
                res += (rem + '0');
            else
                res += (rem - 10 + 'A');
        }
        reverse(res.begin(), res.end());
        return res;
    }

    string minusOne(string s) {
        int i = s.size() - 1;
        while (i >= 0 && s[i] == '0') {
            s[i] = '9';
            i--;
        }
        if (i >= 0)
            s[i]--;

        // remove leading zeros
        int pos = 0;
        while (pos + 1 < s.size() && s[pos] == '0')
            pos++;
        return s.substr(pos);
    }

public:
    int countNumbers(string l, string r, int b) {
        string left = (l == "0") ? "0" : toBase(minusOne(l), b);
        string right = toBase(r, b);
        memset(dp, -1, sizeof(dp));
        int cntR = solve(0, 1, -1, right, b);
        memset(dp, -1, sizeof(dp));
        int cntL = (l == "0") ? 0 : solve(0, 1, -1, left, b);

        return (cntR - cntL + MOD) % MOD;
    }
};