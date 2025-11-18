class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {

        // 1. Assign new groups to items with group -1
        int newGroup = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = newGroup++;
            }
        }
        int totalGroups = newGroup;

        // Graphs
        vector<vector<int>> itemAdj(n);
        vector<int> itemIndeg(n, 0);

        vector<vector<int>> groupAdj(totalGroups);
        vector<int> groupIndeg(totalGroups, 0);

        // 2. Build both item-level and group-level graphs
        for (int i = 0; i < n; i++) {
            for (int b : beforeItems[i]) {

                // item dependency: b → i
                itemAdj[b].push_back(i);
                itemIndeg[i]++;

                // group dependency (only if different groups)
                if (group[b] != group[i]) {
                    groupAdj[group[b]].push_back(group[i]);
                    groupIndeg[group[i]]++;
                }
            }
        }

        // 3. Generic topological sort function
        auto topo = [&](vector<vector<int>>& adj, vector<int>& indeg, int size) {
            queue<int> q;
            for (int i = 0; i < size; i++) {
                if (indeg[i] == 0) q.push(i);
            }

            vector<int> order;
            while (!q.empty()) {
                int u = q.front(); q.pop();
                order.push_back(u);

                for (int v : adj[u]) {
                    if (--indeg[v] == 0) q.push(v);
                }
            }

            if (order.size() == size) return order;
            return vector<int>();   // cycle found
        };

        // 4. Toposort groups
        vector<int> groupOrder = topo(groupAdj, groupIndeg, totalGroups);
        if (groupOrder.empty()) return {};

        // 5. Toposort items
        vector<int> itemOrder = topo(itemAdj, itemIndeg, n);
        if (itemOrder.empty()) return {};

        // 6. Bucket items into their groups (in itemOrder)
        vector<vector<int>> itemsInGroup(totalGroups);
        for (int item : itemOrder) {
            itemsInGroup[group[item]].push_back(item);
        }

        // 7. Build final answer following group order
        vector<int> result;
        for (int g : groupOrder) {
            for (int item : itemsInGroup[g]) {
                result.push_back(item);
            }
        }

        return result;
    }
};
