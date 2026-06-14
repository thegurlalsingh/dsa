class Solution {
    pair<vector<int>, vector<int>> solve(vector<int>& nums){
        int n = nums.size();

        vector<int> len(n, 1);
        vector<int> cnt(n, 1);

        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < i; j++) {

                if (nums[j] < nums[i]) {

                    if (len[j] + 1 > len[i]) {
                        len[i] = len[j] + 1;
                        cnt[i] = cnt[j];
                    }

                    else if (len[j] + 1 == len[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }

            maxLen = max(maxLen, len[i]);
        }

        return {cnt, len};
    }
public:
    int findNumberOfLIS(vector<int>& nums) {
        auto t = solve(nums);
        vector<int> cnt = t.first; 
        vector<int> len = t.second;
        int n = nums.size();
        int maxLen = *max_element(len.begin(), len.end());
        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (len[i] == maxLen) {
                ans += cnt[i];
            }
        }
        return ans;
    }
};