class Solution {
private:
    int findSubset(int idx, vector<int>& arr, vector<int>& dp, vector<int>& hash) {
    if (dp[idx] != -1) {
        return dp[idx]; 
    }

    int maxLength = 1; 
    hash[idx] = idx;   

    for (int prev_index = 0; prev_index < idx; prev_index++) {
        if (arr[idx] % arr[prev_index] == 0) {
            int currLength = 1 + findSubset(prev_index, arr, dp, hash);
            if (currLength > maxLength) {
                maxLength = currLength;
                hash[idx] = prev_index;
            }
        }
    }

    return dp[idx] = maxLength; 
}

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(), nums.end());

        vector<int> dp(n, -1);   
        vector<int> hash(n);     

        int ans = 1, lastIndex = 0;
        for (int i = 0; i < n; i++) {
            int length = findSubset(i, nums, dp, hash);
            if (length > ans) {
                ans = length;
                lastIndex = i;
            }
        }

        vector<int> temp;
        temp.push_back(nums[lastIndex]);
        while (hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(nums[lastIndex]);
        }

        reverse(temp.begin(), temp.end());

        return temp;
    }
};