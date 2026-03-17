class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> freq;
        for(int i = 0; i < nums1.size(); i++){
            freq[nums1[i]]++;
            freq[nums2[i]]++;
        }

        for(auto& p : freq){
            if(p.second % 2 != 0){
                return -1;
            }
        }

        unordered_map<int, int> mp1;
        for(int i = 0; i < nums1.size(); i++){
            mp1[nums1[i]]++;
        }

        int ans = 0;

        for(auto &p : freq){
            int elem = p.first;
            int req = p.second / 2;
            int have = mp1[elem];

            if(have > req){
                ans += (have - req);
            }
        }

        return ans;
    }
};