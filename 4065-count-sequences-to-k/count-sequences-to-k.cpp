struct Rational {
    long long num;
    long long den;

    Rational(long long n, long long d) {
        long long g = gcd(n, d);
        num = n / g;
        den = d / g;
    }
};

class Solution {
    unordered_map<string,int> memo;

    int f(vector<int>& nums, long long k, Rational r, int i){

        if(i == nums.size()){
            return (r.num == k && r.den == 1);
        }

        string key = to_string(i) + "#" + 
                     to_string(r.num) + "#" + 
                     to_string(r.den);

        if(memo.count(key))
            return memo[key];

        int ans = 0;

        Rational mul(r.num * nums[i], r.den);
        ans += f(nums, k, mul, i+1);

        // divide
        Rational div(r.num, r.den * nums[i]);
        ans += f(nums, k, div, i+1);

        // skip
        ans += f(nums, k, r, i+1);

        return memo[key] = ans;
    }

public:
    int countSequences(vector<int>& nums, long long k) {
        memo.clear();
        Rational start(1,1);
        return f(nums, k, start, 0);
    }
};