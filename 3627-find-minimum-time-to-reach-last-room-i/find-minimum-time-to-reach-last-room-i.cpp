typedef pair<int, pair<int, int>> p;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size(), m = moveTime[0].size();
        priority_queue<p, vector<p>, greater<>> pq;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        pq.push({0, {0, 0}});

        while (!pq.empty()) {
            auto [time, cell] = pq.top(); pq.pop();
            int row = cell.first, col = cell.second;

            if (visited[row][col]) continue;
            visited[row][col] = true;

            if (row == n - 1 && col == m - 1)
                return time;

            for (auto [dr, dc] : directions) {
                int nr = row + dr, nc = col + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < m && !visited[nr][nc]) {
                    int waitTime = moveTime[nr][nc];
                    int newTime = max(waitTime + 1, time + 1);
                    pq.push({newTime, {nr, nc}});
                }
            }
        }

        return -1; 
    }
};
