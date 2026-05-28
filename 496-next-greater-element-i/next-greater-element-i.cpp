class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> temp(nums2.size());
        stack<int> st;
        for(int i = nums2.size() - 1; i >= 0; i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }
            if(st.empty()){
                temp[i] = -1;
            }
            else{
                temp[i] = st.top();
            }
            st.push(nums2[i]);
        }
        
        vector<int> ans(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++){
            int x = nums1[i];
            for(int j = 0; j < nums2.size(); j++){
                if(nums2[j] == x){
                    ans[i] = temp[j];
                }
            }
        }
       
        return ans;
    }
};