class Solution {
private:
    bool backtrack(int index, int target, vector<int>& matchsticks, vector<int>& sides) {
        if (index == matchsticks.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }

        for (int i = 0; i < 4; ++i) {
            if (sides[i] + matchsticks[index] <= target) {
                sides[i] += matchsticks[index]; 
                if (backtrack(index + 1, target, matchsticks, sides)) {
                    return true;  
                }
                sides[i] -= matchsticks[index];  
            }

            if (sides[i] == 0) {
                break;  
            }
        }

        return false;
    }

public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);        
        if (total % 4 != 0) {
            return false;
        }

        int target = total / 4;  
        vector<int> sides(4, 0); 

        sort(matchsticks.begin(), matchsticks.end(), greater<int>());

        return backtrack(0, target, matchsticks, sides);
    }
};

