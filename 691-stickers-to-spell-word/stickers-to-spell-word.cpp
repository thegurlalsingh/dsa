class Solution {
    int memo[1 << 15];  // memoization for up to 15 target letters

    int dfs(int mask, string& target, vector<vector<int>>& stickerFreq, int allMask) {
        // Base case: if all target characters are covered
        if (mask == allMask) return 0;

        // If already computed
        if (memo[mask]) return memo[mask];

        int minStickers = 51; // sentinel (max target length <= 15)

        // Try using each sticker
        for (auto sticker : stickerFreq) {
            int newMask = mask;

            // Try to cover as many uncovered target letters as possible with this sticker
            for (int i = 0; i < target.size(); ++i) {
                int bit = 1 << i;
                if ((mask & bit) == 0 && sticker[target[i] - 'a'] > 0) {
                    newMask |= bit;                     // mark letter as covered
                    sticker[target[i] - 'a']--;         // use one letter
                }
            }

            // If this sticker helped progress (covered something new)
            if (newMask != mask) {
                minStickers = min(minStickers, 1 + dfs(newMask, target, stickerFreq, allMask));
            }
        }

        // Store and return result
        return memo[mask] = minStickers;
    }

public:
    int minStickers(vector<string>& stickers, string target) {
        int n = stickers.size();
        vector<vector<int>> stickerFreq(n, vector<int>(26, 0));
        memset(memo, 0, sizeof(memo));

        // Convert each sticker to a frequency map
        for (int i = 0; i < n; ++i)
            for (char c : stickers[i])
                stickerFreq[i][c - 'a']++;

        int allMask = (1 << target.size()) - 1; // all target characters formed
        int result = dfs(0, target, stickerFreq, allMask);

        return (result < 51) ? result : -1;
    }
};
