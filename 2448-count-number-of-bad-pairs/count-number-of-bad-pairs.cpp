class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long n = nums.size();
        long long total_pairs = (n * (n - 1))/2;
        unordered_map<long long, long long> m;
        for(int i = 0; i < nums.size(); i++){
            long long f = nums[i] - i;
            if(m.find(f) != m.end()){
                total_pairs -= m[f];
            }
            m[f] += 1;
        }
        return total_pairs;
    }
};