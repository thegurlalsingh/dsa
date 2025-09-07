class Solution {
public:
    int minOperations(string s) {
        int ans = 0;
        for (char c : s) {
            int dist = ('a' - c + 26) % 26;
            ans = max(ans, dist);
        }
        return ans;
    }
};
