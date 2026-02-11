class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long sum = 1LL * n * (n + 1) / 2;
        long long neg_sum = sum - target;
        if(neg_sum < 0 || neg_sum % 2 != 0 || abs(sum) < abs(target)) return {};
        neg_sum /= 2;

        vector<int> perm(n);
        for(int i = 0; i < n; i++) perm[i] = i + 1;

        // pick numbers to negate greedily from largest to smallest
        for(int i = n; i >= 1; i--){
            if(i <= neg_sum){
                perm[i-1] = -perm[i-1];
                neg_sum -= i;
            }
        }
        sort(perm.begin(), perm.end());
        // perm is already in lexicographically smallest order
        return perm;
    }
};
