class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<long long> degree(n, 0);
        for(int i = 0; i < roads.size(); i++){
            degree[roads[i][0]]++; degree[roads[i][1]]++;
        }
        priority_queue<pair<long long, long long>> pq;
        long long c = n;
        vector<long long> cost(n, 0);
        for(int i = 0; i < degree.size(); i++){
            pq.push({degree[i], i});
        }
        while(!pq.empty()){
            cost[pq.top().second] = n; n--; pq.pop();
        }
        long long res = 0;
        for(int i = 0; i < roads.size(); i++){
            res += cost[roads[i][0]] + cost[roads[i][1]];
        }
        return res;
    }
};