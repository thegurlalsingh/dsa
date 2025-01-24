class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        set<pair<int,int>> s;
        for(int i = 0; i < circles.size(); i++){
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];
            for(int j = 0; j <= max(x+r, y+r); j++){
                for(int k = 0; k <= max(x+r, y+r); k++){
                    if(sqrt(pow(x - j, 2) + pow(y - k, 2)) <= r){
                        s.insert({j,k});
                    }
                }
            }
        }
        return s.size();
    }
};


