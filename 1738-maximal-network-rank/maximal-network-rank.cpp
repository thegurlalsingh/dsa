class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        vector<vector<bool>> connected(n, vector<bool>(n, false));

        // Count degrees and store direct connections
        for (auto& r : roads) {
            int a = r[0], b = r[1];
            degree[a]++;
            degree[b]++;
            connected[a][b] = connected[b][a] = true;
        }

        int ans = 0;

        // Try all pairs (i, j)
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int rank = degree[i] + degree[j];
                if (connected[i][j]) rank--; // subtract double counted road
                ans = max(ans, rank);
            }
        }

        return ans;
    }
};
