class Solution {
public:
    
    int n, m;

    bool valid(int i, int j){
        return i >= 0 && j >= 0 && i < n && j < m;
    }

    // binary search: last index with value <= val
    int lastIndex(vector<tuple<int,int,int>>& vec, int val){
        int l = 0, r = vec.size() - 1, ans = -1;

        while(l <= r){
            int mid = (l + r) / 2;

            if(get<0>(vec[mid]) <= val){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }

        return ans;
    }

    int minCost(vector<vector<int>>& grid, int k) {

        n = grid.size();
        m = grid[0].size();

        vector<int> visitedforeachk(k + 1, 0);

        // flatten grid
        vector<tuple<int,int,int>> vec;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vec.push_back({grid[i][j], i, j});
            }
        }

        // sort by value
        sort(vec.begin(), vec.end());

        // dist[x][y][usedTeleports]
        vector<vector<vector<int>>> dist(
            n, vector<vector<int>>(m, vector<int>(k + 1, INT_MAX))
        );

        priority_queue<
            tuple<int,int,int,int>,
            vector<tuple<int,int,int,int>>,
            greater<tuple<int,int,int,int>>
        > pq;

        pq.push({0, 0, 0, 0});  // cost, teleportsUsed, x, y
        dist[0][0][0] = 0;

        while(!pq.empty()){

            auto [cost, currk, i, j] = pq.top();
            pq.pop();

            if(cost > dist[i][j][currk]) continue;

            if(i == n - 1 && j == m - 1) return cost;

            int newcost;

            // move down
            if(valid(i + 1, j)){
                newcost = cost + grid[i + 1][j];

                if(newcost < dist[i + 1][j][currk]){
                    dist[i + 1][j][currk] = newcost;
                    pq.push({newcost, currk, i + 1, j});
                }
            }

            // move right
            if(valid(i, j + 1)){
                newcost = cost + grid[i][j + 1];

                if(newcost < dist[i][j + 1][currk]){
                    dist[i][j + 1][currk] = newcost;
                    pq.push({newcost, currk, i, j + 1});
                }
            }

            // teleport
            if(currk < k){

                int limit = lastIndex(vec, grid[i][j]);

                for(int r = visitedforeachk[currk]; r <= limit; r++){

                    auto [c, ni, nj] = vec[r];

                    if(cost < dist[ni][nj][currk + 1]){
                        dist[ni][nj][currk + 1] = cost;
                        pq.push({cost, currk + 1, ni, nj});
                    }
                }

                visitedforeachk[currk] =
                    max(visitedforeachk[currk], limit + 1);
            }
        }

        return -1;
    }
};