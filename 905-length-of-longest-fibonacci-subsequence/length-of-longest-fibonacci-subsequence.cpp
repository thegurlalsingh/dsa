class Solution {
private:
    int findFibLikeLength(int a, int b, unordered_set<int>& nums) {
        if (nums.find(a + b) == nums.end()) {
            return 2; 
        }
        return 1 + findFibLikeLength(b, a + b, nums); 
    }

public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_set<int> nums(arr.begin(), arr.end()); 
        int maxLen = 0;
        int n = arr.size();

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                maxLen = max(maxLen, findFibLikeLength(arr[i], arr[j], nums));
            }
        }

        return maxLen > 2 ? maxLen : 0; 
    }
};