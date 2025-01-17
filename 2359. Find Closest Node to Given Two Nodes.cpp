class Solution {
private:
    vector<int> dijkstra(int n, int start, const vector<int>& edges) {
        vector<int> dist(n, INT_MAX); 
        dist[start] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start}); 
        
        while (!pq.empty()) {
            auto [currentDist, currentNode] = pq.top();
            pq.pop();
            
            if (currentDist > dist[currentNode]) {
                continue; 
            }

            int neighbor = edges[currentNode];
            if (neighbor != -1) { 
                int newDist = currentDist + 1; 
                if (newDist < dist[neighbor]) {
                    dist[neighbor] = newDist;
                    pq.push({newDist, neighbor});
                }
            }
        }
        
        return dist;
    }

public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        
        vector<int> distFromNode1 = dijkstra(n, node1, edges);
        vector<int> distFromNode2 = dijkstra(n, node2, edges);
        
        int minDist = INT_MAX;
        int closestNode = -1;
        
        for (int i = 0; i < n; ++i) {
            if (distFromNode1[i] != INT_MAX && distFromNode2[i] != INT_MAX) {
                int maxDist = max(distFromNode1[i], distFromNode2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    closestNode = i;
                }
            }
        }
        
        return closestNode;
    }
};

