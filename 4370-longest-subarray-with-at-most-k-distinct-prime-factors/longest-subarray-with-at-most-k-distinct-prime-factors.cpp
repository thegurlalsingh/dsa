class Solution {
    vector<int> getPrimes(int n) {
        vector<bool> isPrime(n + 1, true);
        vector<int> primes;

        isPrime[0] = isPrime[1] = false;

        for(long long i = 2; i <= n; i++) {
            if(isPrime[i]) {
                primes.push_back(i);

                for(long long j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        return primes;
    }

    vector<int> getFactors(int n, vector<int>& primes) {
        vector<int> factors;

        for(int p : primes) {

            if(p * p > n)
                break;

            if(n % p == 0) {
                factors.push_back(p);

                while(n % p == 0) {
                    n /= p;
                }
            }
        }

        if(n > 1) {
            factors.push_back(n);
        }

        return factors;
    }

public:
    int longestSubarray(vector<int>& nums, int k) {

        vector<int> primes = getPrimes(100000);

        int i = 0;
        int ans = 0;

        unordered_map<int, int> mp;

        for(int j = 0; j < nums.size(); j++) {

            vector<int> factors = getFactors(nums[j], primes);

            for(int p : factors) {
                mp[p]++;
            }

            while(mp.size() > k) {

                vector<int> leftFactors = getFactors(nums[i], primes);

                for(int p : leftFactors) {
                    mp[p]--;

                    if(mp[p] == 0) {
                        mp.erase(p);
                    }
                }

                i++;
            }

            ans = max(ans, j - i + 1);
        }

        return ans;
    }
};