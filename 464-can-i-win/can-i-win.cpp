class Solution {
    unordered_map<int, bool> dp;
    
    bool canWin(int maxChoosableInteger, int desiredTotal, int mask) {
        if (dp.count(mask)) return dp[mask];
        
        for (int i = 0; i < maxChoosableInteger; i++) {
            int cur = 1 << i;
            if ((mask & cur) == 0) { // if i+1 not used
                if (i + 1 >= desiredTotal || 
                    !canWin(maxChoosableInteger, desiredTotal - (i + 1), mask | cur)) {
                    return dp[mask] = true;
                }
            }
        }
        return dp[mask] = false;
    }

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int sum = (maxChoosableInteger * (maxChoosableInteger + 1)) / 2;
        if (sum < desiredTotal) return false;  // impossible to reach target
        if (desiredTotal <= 0) return true;
        
        return canWin(maxChoosableInteger, desiredTotal, 0);
    }
};
