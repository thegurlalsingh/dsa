#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int,int> dp;
        int ans = 0;

        for (int x : arr) {
            dp[x] = dp[x - difference] + 1;
            ans = max(ans, dp[x]);
        }
        return ans;
    }
};
