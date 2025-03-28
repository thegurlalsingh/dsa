class Solution {
public:

    int m, n;

    bool isValid(int x, int y){
        return (x>=0 && x<m && y>=0 && y<n);
    }

    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& q) {
        m=grid.size(), n=grid[0].size();
        int qs = q.size();
        vector<int> ans(qs, 0);

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({grid[0][0], 0, 0});

        vector<vector<int>> vis(m, vector<int>(n, 0));
        vis[0][0] = 1;

        vector<vector<int>> dir = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        vector<vector<int>> queries(qs);
        for(int i=0; i<qs; i++){
            queries[i] = {q[i], i};
        }
        sort(queries.begin(), queries.end());

        int k = 0;
        while(k<qs){
            int currVal = queries[k][0];
            int count = 0;
            while(!pq.empty() && currVal>pq.top()[0]){
                count++;
                vector<int> tp = pq.top(); pq.pop();
                for(int i=0; i<dir.size(); i++){
                    int newx = tp[1]+dir[i][0];
                    int newy = tp[2]+dir[i][1];
                    if(isValid(newx, newy) && vis[newx][newy]==0){
                        pq.push({grid[newx][newy], newx, newy});
                        vis[newx][newy] = 1;
                    }
                }
            }
            ans[k] = count; k++;
        }

        for(int i=1; i<qs; i++){
            ans[i] = ans[i]+ans[i-1];
        }

        vector<int> res(qs);
        for(int i=0; i<qs; i++){
            int index=queries[i][1];
            int val = ans[i];
            res[index] = val;
        }

        return res;
    }
};