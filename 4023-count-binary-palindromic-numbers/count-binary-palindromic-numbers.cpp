#include <bits/stdc++.h>
using namespace std;

class Solution {
    string toBinary(long long n) {
        if (n == 0) return "0";
        string result;
        while (n > 0) {
            result.push_back(char((n & 1) + '0'));
            n >>= 1;
        }
        reverse(result.begin(), result.end());
        return result;
    }

    bool palindrome(const string &s) {
        int i = 0, j = (int)s.length() - 1;
        while (i < j) {
            if (s[i] != s[j]) return false;
            i++; j--;
        }
        return true;
    }

    // precomputed[len] = number of binary palindromes of exact length `len`
    void p(vector<long long>& precomputed, int maxLen = 63) {
        precomputed.assign(maxLen + 1, 0);
        if (maxLen >= 1) precomputed[1] = 1; // "1"
        if (maxLen >= 2) precomputed[2] = 1; // "11"
        for (int L = 3; L <= maxLen; ++L) {
            int half = (L + 1) / 2;                // number of prefix bits
            precomputed[L] = 1LL << (half - 1);    // 2^(ceil(L/2)-1)
        }
    }

public:
    // kept your signature; count may exceed int for very large n — consider changing to long long if needed
    int countBinaryPalindromes(long long n) {
        if (n < 0) return 0;
        if(n == 0){
            return 1;
        }

        vector<long long> precomputed;
        p(precomputed, 63);            // support up to 63-bit numbers

        string b = toBinary(n);
        int L = (int)b.length();

        long long count = 0;
        // add palindromes of length strictly less than L
        for (int len = 1; len < L; ++len) {
            count += precomputed[len];
        }

        // Now count palindromes of length == L and <= n
        int k = (L + 1) / 2;                // prefix length
        long long startPrefix = 1LL << (k - 1); // smallest prefix (binary starts with 1)
        long long prefixN = stoll(b.substr(0, k), nullptr, 2);

        // all prefixes strictly less than prefixN produce palindromes < n
        if (prefixN > startPrefix) {
            count += (prefixN - startPrefix);
        }

        // build the palindrome from prefixN and check if it's <= n
        string pre = b.substr(0, k);
        string pal = pre;
        int j = (L % 2 == 1) ? k - 2 : k - 1;
        for (; j >= 0; --j) pal.push_back(pre[j]);

        long long palVal = stoll(pal, nullptr, 2);
        if (palVal <= n) count++;

        return (int)count + 1;
    }
};

