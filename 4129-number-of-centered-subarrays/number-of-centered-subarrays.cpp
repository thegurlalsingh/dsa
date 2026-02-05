class Solution {
    vector<vector<int>> generateSubarrays(const vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> subarrays;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = i; j < n; j++) {
                temp.push_back(arr[j]);
                subarrays.push_back(temp);
            }
        }
        return subarrays;
    }

    bool exists(const vector<int>& v, int x) {
        return find(v.begin(), v.end(), x) != v.end();
    }
public:
    int centeredSubarrays(vector<int>& nums) {
        vector<vector<int>> sub = generateSubarrays(nums);
        int count = 0;
        for(int i = 0; i < sub.size(); i++){
            int sum = accumulate(sub[i].begin(), sub[i].end(), 0);
            if(exists(sub[i], sum)){
                count++;
            }
        }
        return count;
    }
};