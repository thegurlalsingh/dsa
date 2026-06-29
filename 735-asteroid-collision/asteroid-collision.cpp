class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        for (int i = 0; i < asteroids.size(); i++) {
            bool push = true;
            if (asteroids[i] < 0) {
                while (!ans.empty() && ans.back() > 0 &&
                       (abs(ans.back()) < abs(asteroids[i]))) {
                    ans.pop_back();
                }
                if (!ans.empty() && ans.back() > 0 &&
                    (abs(ans.back()) > abs(asteroids[i]))) {
                    push = false;
                }
                if (!ans.empty() && ans.back() > 0 &&
                       (abs(ans.back()) == abs(asteroids[i]))) {
                    push = false;
                    ans.pop_back();
                }
            }
            if (push) {
                ans.push_back(asteroids[i]);
            }
        }
        return ans;
    }
};