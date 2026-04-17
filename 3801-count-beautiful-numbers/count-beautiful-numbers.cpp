class Solution {
    int solve(int pos, int tight, int started, string &s, int prod, int sum, unordered_map<string, long long> &mp) {    
        
        if (pos == s.size()) {
            if (!started) return 0;
            if (sum == 0) return 0;
            return (prod % sum == 0);
        }

        string key = to_string(pos) + "|" + to_string(tight) + "|" + 
                     to_string(started) + "|" + to_string(prod) + "|" + to_string(sum);

        if (mp.count(key))
            return mp[key];

        long long ans = 0;

        int limit = (tight ? s[pos] - '0' : 9);

        for (int d = 0; d <= limit; d++) {

            int new_tight = (tight && (d == limit));
            int new_started = (started || (d != 0));

            int new_prod = prod;
            int new_sum = sum;

            if (new_started) {
                if (!started) {
                    // first non-zero digit
                    new_prod = d;
                    new_sum = d;
                } else {
                    new_prod = prod * d;
                    new_sum = sum + d;
                }
            }

            ans += solve(pos + 1, new_tight, new_started, s, new_prod, new_sum, mp);
        }

        return mp[key] = ans;
    }

public:
    int beautifulNumbers(int l, int r) {
        string left = to_string(l - 1);
        string right = to_string(r);

        unordered_map<string, long long> mp1, mp2;

        return solve(0, 1, 0, right, 1, 0, mp1) - 
               solve(0, 1, 0, left, 1, 0, mp2);
    }
};