class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {
        int m = classroom.size();
        int n = classroom[0].size();

        int startx = 0, starty = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(classroom[i][j] == 'S'){
                    startx = i; starty = j;
                }
            }
        }

        vector<pair<int,int>> s;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(classroom[i][j] == 'L'){
                    s.push_back({i, j});
                }
            }
        }

        int litter = s.size();

        queue<tuple<int,int,int,int,int>> q; // x,y,energy,bitmask,steps
        q.push({startx, starty, energy, 0, 0});

        // visited[x][y][mask] = max energy seen
        map<tuple<int,int,int>, int> visited;

        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};

        while(!q.empty()){
            auto [x,y,e,b,st] = q.front();
            q.pop();

            if(b == (1 << litter) - 1) return st;
            if(e == 0 && classroom[x][y] != 'R') continue;

            auto key = make_tuple(x,y,b);
            if(visited.count(key) && visited[key] >= e) continue;
            visited[key] = e;

            for(int k = 0; k < 4; k++){
                int nr = x + dr[k];
                int nc = y + dc[k];

                if(nr < 0 || nc < 0 || nr >= m || nc >= n) continue;
                if(classroom[nr][nc] == 'X') continue;

                int newe = e - 1;
                int newb = b;

                if(classroom[nr][nc] == 'L'){
                    for(int i = 0; i < litter; i++){
                        if(s[i] == make_pair(nr,nc)){
                            newb |= (1 << i);
                            break;
                        }
                    }
                }

                if(classroom[nr][nc] == 'R'){
                    newe = energy;
                }

                if(newe < 0) continue;

                q.push({nr, nc, newe, newb, st + 1});
            }
        }

        return -1;
    }
};