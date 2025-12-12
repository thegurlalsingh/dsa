class Solution {
    vector<int> sieve(int n) {
        vector<bool> prime(n + 1, true);
        if (n < 2) return {};

        prime[0] = prime[1] = false;

        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        vector<int> ans;
        for (int i = 2; i <= n; i++)
            if (prime[i])
                ans.push_back(i);

        return ans;
    }

public:
    int largestPrime(int n) {
        vector<int> p = sieve(n);
        if (p.empty()) return 0;

        unordered_set<long long> s;
        
        long long last = p[0];
        s.insert(last);

        for (int i = 1; i < (int)p.size(); i++) {
            last += p[i];       
            s.insert(last);
        }

        for (int i = (int)p.size() - 1; i >= 0; i--) {
            if (s.count(p[i]))
                return p[i];
        }

        return 0;
    }
};
