class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        int n = nums.size();
        stack<int> st;
        long long ans = 0;

        for(int i = 0; i < n; i++) {
            while(!st.empty() && nums[i] > nums[st.top()]) {
                int mid = st.top();
                st.pop();
                
                if(!st.empty()) {
                    int left = st.top();
                    
                    if(i - left + 1 >= 3) {
                        ans++;
                    }
                }
            }
            st.push(i);
        }
        return ans;
    }
};