class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        queue<int> q;
        vector<vector<int>> dp(n, vector<int>(26, 0));

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) q.push(i);
        }

        int visited = 0;
        int result = 0;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            visited++;

            int colorIdx = colors[node] - 'a';
            dp[node][colorIdx]++;

            result = max(result, dp[node][colorIdx]);

            for (int nei : adj[node]) {
                for (int c = 0; c < 26; c++) {
                    dp[nei][c] = max(dp[nei][c], dp[node][c]);
                }
                if (--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        if(visited == n){
            return result;
        }
        return -1;
    }
};
