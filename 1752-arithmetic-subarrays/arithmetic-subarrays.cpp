class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = l.size();
        vector<bool> res(m, true);
        for(int i = 0; i < m; i++){
            int start = l[i];
            int end = r[i];
            vector<int> v1(nums.begin() + start, nums.begin() + end + 1);
            sort(v1.begin(), v1.end());
            int diff = v1[1] - v1[0];
            for(int j = 0; j < v1.size() - 1; j++){
                if((v1[j + 1] - v1[j]) != diff){
                    res[i] = false;
                    break;
                }
            }
        }
        return res;
    }
};