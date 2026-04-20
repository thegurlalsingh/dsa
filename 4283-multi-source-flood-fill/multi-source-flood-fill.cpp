struct hash_pair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n, vector<int>(m, 0));
        for(int i = 0; i < sources.size(); i++){
            int x = sources[i][0];
            int y = sources[i][1];
            int w = sources[i][2];
            grid[x][y] = w;
        }

        queue<pair<int, int>> q;
        unordered_set<pair<int, int>, hash_pair> st;
        vector<int> dr = {-1, 1, 0, 0}; 
        vector<int> dc = {0, 0, -1, 1}; 
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] != 0){
                    q.push({i, j});
                }
                else{
                    st.insert({i, j});
                }
            }
        }
        while(!st.empty()){
            vector<pair<int, int>> temp;
            unordered_set<pair<int, int>, hash_pair> removed;
            while(!q.empty()){
                temp.push_back(q.front());
                q.pop();
            }
            for(int i = 0; i < temp.size(); i++){
                int x = temp[i].first; int y = temp[i].second;
                for(int j = 0; j < 4; j++) {
                    int nr = x + dr[j];
                    int nc = y + dc[j];
                    if(st.find({nr, nc}) != st.end()){
                        removed.insert({nr, nc});
                        grid[nr][nc] = max(grid[nr][nc], grid[x][y]);
                    }
                }
            }
            for(auto& p : removed){
                if(st.find(p) != st.end()){
                    st.erase(p);
                    q.push(p);
                }
            }
        }
        return grid;
    }
};