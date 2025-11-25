#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int,int>> P; // {cost, {timeUsed, node}}
const int INF = 1e9;

class Solution {
    int dijkstraToDest(vector<vector<pair<int,int>>>& adj,
                       int src, int dest,
                       vector<int>& passingFees,
                       int maxTime) {

        int n = adj.size();

        // dp[node][time] = min cost to reach node using exactly time
        vector<vector<int>> dp(n, vector<int>(maxTime + 1, INF));

        // min-heap ordered by cost
        priority_queue<P, vector<P>, greater<P>> pq;

        // start at src with time 0 and cost = passing fee of src
        dp[src][0] = passingFees[src];
        pq.push({passingFees[src], {0, src}});

        while (!pq.empty()) {
            auto top = pq.top(); pq.pop();
            int cost = top.first;
            int timeUsed = top.second.first;
            int u = top.second.second;

            // stale state
            if (cost > dp[u][timeUsed]) continue;

            // if we reached dest within allowed time, return cost (pq ensures min cost)
            if (u == dest) return cost;

            for (auto &e : adj[u]) {
                int v = e.first;
                int tEdge = e.second;
                int newTime = timeUsed + tEdge;
                if (newTime > maxTime) continue;

                int newCost = cost + passingFees[v];

                if (newCost < dp[v][newTime]) {
                    dp[v][newTime] = newCost;
                    pq.push({newCost, {newTime, v}});
                }
            }
        }

        // if we never popped dest, check dp table for best cost within time
        int best = INF;
        for (int t = 0; t <= maxTime; ++t) best = min(best, dp[dest][t]);
        return (best == INF) ? -1 : best;
    }

public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<vector<pair<int,int>>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }
        return dijkstraToDest(adj, 0, n - 1, passingFees, maxTime);
    }
};
