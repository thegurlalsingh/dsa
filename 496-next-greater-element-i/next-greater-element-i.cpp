class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int, int> mp;
        for(int j = 0; j < nums2.size(); j++){
            mp[nums2[j]] = j;   
        }

        vector<int> ans(nums1.size(), -1);

        for(int i = 0; i < nums1.size(); i++){
            int start = mp[nums1[i]];

            for(int j = start + 1; j < nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    ans[i] = nums2[j];
                    break;
                }
            }
        }

        return ans;
    }
};
