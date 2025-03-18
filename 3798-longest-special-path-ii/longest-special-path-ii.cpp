class Solution {
public:
    int maxLength = 0, minNodes = INT_MAX;

    void dfs(int node, int parent, vector<vector<pair<int, int>>>& gr, vector<int>& nums, int sum, int start, int end, 
             unordered_map<int, int>& indexMap, vector<int>& path, int twice) {
        
        int prev = indexMap.count(nums[node]) ? indexMap[nums[node]] : -1;
        indexMap[nums[node]] = end;

        while (start <= min(prev, twice)) {
            sum -= path[start++];
        }
        if (prev != -1) {
            twice = max(twice, prev);
        }

        if (sum > maxLength) {
            maxLength = sum;
            minNodes = end - start + 1;
        } else if (sum == maxLength) {
            minNodes = min(minNodes, end - start + 1);
        }

        for (auto& [neighbor, weight] : gr[node]) {
            if (neighbor != parent) {
                path.push_back(weight);
                dfs(neighbor, node, gr, nums, sum + weight, start, end + 1, indexMap, path, twice);
                path.pop_back();
            }
        }

        indexMap[nums[node]] = prev;
    }

    vector<int> longestSpecialPath(vector<vector<int>>& edges, vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> gr(n);
        
        for (auto& edge : edges) {
            gr[edge[0]].emplace_back(edge[1], edge[2]);
            gr[edge[1]].emplace_back(edge[0], edge[2]);
        }

        unordered_map<int, int> indexMap;
        vector<int> path;
        dfs(0, -1, gr, nums, 0, 0, 0, indexMap, path, -1);

        return {maxLength, minNodes};
    }
};