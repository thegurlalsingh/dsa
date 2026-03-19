class Solution {
public:
    int maximumSum(vector<int>& nums) {
        vector<int> edited = nums;
        for(int i = 0; i < edited.size(); i++){
            edited[i] = edited[i] % 3;
        }
        vector<int> n0, n1, n2;
        for(int i = 0; i < edited.size(); i++){
            if(edited[i] == 0){
                n0.push_back(nums[i]);
            }
            else if(edited[i] == 1){
                n1.push_back(nums[i]);
            }
            else{
                n2.push_back(nums[i]);
            }
        }
        int only0 = 0; int sn0 = n0.size();
        sort(n0.begin(), n0.end()); sort(n1.begin(), n1.end()); sort(n2.begin(), n2.end());
        if(n0.size() >= 3){
            only0 += (n0[sn0 - 1] + n0[sn0 - 2] + n0[sn0 - 3]);
        }
        int only1 = 0; int sn1 = n1.size();
        if(n1.size() >= 3){
            only1 += (n1[sn1 - 1] + n1[sn1 - 2] + n1[sn1 - 3]);
        }
        int only2 = 0; int sn2 = n2.size();
        if(n2.size() >= 3){
            only2 += (n2[sn2 - 1] + n2[sn2 - 2] + n2[sn2 - 3]);
        }
        int mixed = 0;
        
        if(sn0 >= 1 && sn1 >= 1 && sn2 >= 1){
            mixed += (n0[sn0 - 1] + n1[sn1 - 1] + n2[sn2 - 1]);
        }
        return max({only0, only1, only2, mixed});
    }
};