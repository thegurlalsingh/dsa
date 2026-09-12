class Solution {
private:
    int dfs(int currentCity, int remainingStops, int dst, unordered_map<int, vector<pair<int, int>>>& adj, vector<vector<int>>& memo) {
        if (remainingStops < 0) {
            return INT_MAX; 
        }
        if (currentCity == dst) {
            return 0; 
        }
        if (memo[currentCity][remainingStops] != -1) {
            return memo[currentCity][remainingStops]; 
        }
        
        int minCost = INT_MAX;
        
        for (auto& [nextCity, cost] : adj[currentCity]) {
            int nextCost = dfs(nextCity, remainingStops - 1, dst, adj, memo);
            if (nextCost != INT_MAX) {
                minCost = min(minCost, cost + nextCost);
            }
        }
        
        return memo[currentCity][remainingStops] = minCost;
    }

public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for (auto& flight : flights) {
            adj[flight[0]].emplace_back(flight[1], flight[2]);
        }
        
        vector<vector<int>> memo(n, vector<int>(k + 2, -1)); // as we are going from 0 to k + 1 stops we need k + 2 flights, thats why here it is k + 2
        
        int result = dfs(src, k + 1, dst, adj, memo); // starting from k + 1 because for atmost x stops -> x + 1 flights are needed
        return result == INT_MAX ? -1 : result;
    }
};
