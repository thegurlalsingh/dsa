class Solution {
    // int manhattan(int x1, int y1, int x2, int y2){
    //     return abs(x2 - x1) + abs(y2 - y1);
    // } // done use manhattan distance because with manhattan distance we will lose direction but with storing actual cordinates we can use them to shift ones cells in img1 

    int solve(int i, int j, vector<pair<int, int>>& ones1, vector<pair<int, int>>& ones2, vector<vector<int>>& dp){
        if(i >= ones1.size() || j >= ones2.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int skip1 = solve(i + 1, j, ones1, ones2, dp);
        int skip2 = solve(i, j + 1, ones1, ones2, dp);
        int take = 0;
        if(ones1[i] == ones2[j]){
            take = 1 + solve(i + 1, j + 1, ones1, ones2, dp);
        }
        int ans = max(skip1, skip2);
        ans = max(ans, take);
        return dp[i][j] = ans;
    }
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;

        for(int i = 0; i < img2.size(); i++){
            for(int j = 0; j < img2.size(); j++){
                if(img2[i][j] == 1){
                    ones2.push_back({i, j});
                }
            }
        }

        for(int i = 0; i < img1.size(); i++){
            for(int j = 0; j < img1.size(); j++){
                if(img1[i][j] == 1){
                    ones1.push_back({i, j});
                }
            }
        }

        map<pair<int, int>, int> mp;
        
        for(int i = 0; i < ones1.size(); i++){
            for(int j = 0; j < ones2.size(); j++){
                auto [x1, y1] = ones1[i]; 
                auto [x2, y2] = ones2[j];
                int dx = x2 - x1;
                int dy = y2 - y1;
                mp[{dx, dy}]++;
            } // storing that difference in cordinates which occurs the most because that is the main overlapping difference between img1 and img2
        }
        
        int maxiFreq = 0; pair<int, int> maxi = {0, 0};

        for(auto p : mp){
            if(p.second > maxiFreq){
                maxi = p.first;
                maxiFreq = p.second;
            }
        }

        for(int i = 0; i < ones1.size(); i++){
            ones1[i].first += maxi.first;
            ones1[i].second += maxi.second;
        }

        sort(ones1.begin(), ones1.end());
        sort(ones2.begin(), ones2.end());

        int i = 0; int j = 0;
        vector<vector<int>> dp(901, vector<int>(901, -1));
        int overlaps = solve(0, 0, ones1, ones2, dp);
        return overlaps;
    }
};