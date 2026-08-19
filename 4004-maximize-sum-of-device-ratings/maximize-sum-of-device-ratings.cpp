class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int n = units[0].size();
        if(n == 1){
            long long ans = 0;

            for(auto& r : units){
                ans += r[0];
            }
            return ans;
        }
        vector<long long> minimum(units.size(), -1); vector<long long> secondMin(units.size(), -1); 
        for(int i = 0; i < units.size(); i++){
            sort(units[i].begin(), units[i].end());
            secondMin[i] = (units[i].size() > 1 ? units[i][1] : 0);
            minimum[i] = (units[i].size() > 0 ? units[i][0] : 0);
        }
        long long globalMinimum = *min_element(minimum.begin(), minimum.end());
        long long secondMinSum = accumulate(secondMin.begin(), secondMin.end(), 0LL);
        long long ans = 0;
        for(int i = 0; i < minimum.size(); i++){
            ans = max(ans, secondMinSum - secondMin[i] + globalMinimum);
        }
        return ans;
    }
};