class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0; int j = height.size() - 1;
        int ans = INT_MIN;
        while(i < j){
            int water = min(height[i], height[j]) * abs(j - i);
            ans = max(water, ans);
            if(height[i] > height[j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};