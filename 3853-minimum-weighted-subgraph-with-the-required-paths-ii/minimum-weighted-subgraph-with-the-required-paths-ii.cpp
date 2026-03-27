#define ll long long

struct LCA {
    int n, LOG = 20;
    vector<vector<int>> parent;
    vector<int> lvl;
    vector<int> dist;
    vector<vector<pair<int,int>>> adj;

    LCA(int n){
        this->n = n;
        parent.assign(n, vector<int>(LOG, -1));
        lvl.assign(n, 0);
        dist.assign(n, 0);
        adj.resize(n);
    }

    void addEdge(int u, int v, int w){
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    void dfs(int root = 0){
        stack<tuple<int,int,ll,int>> st;
        st.push({root, 0, 0LL, -1});

        while(!st.empty()){
            auto [node, level, d, par] = st.top();
            st.pop();

            lvl[node] = level;
            dist[node] = d;
            parent[node][0] = par;

            for(auto &[child, w] : adj[node]){
                if(child != par){
                    st.push({child, level+1, d+w, node});
                }
            }
        }
    }

    void build(){
        for(int i = 1; i < LOG; i++){
            for(int j = 0; j < n; j++){
                if(parent[j][i-1] != -1){
                    parent[j][i] = parent[parent[j][i-1]][i-1];
                }
            }
        }
    }

    int kth(int u, int k){
        for(int i = 0; i < LOG; i++){
            if(k & (1<<i)){
                u = parent[u][i];
                if(u == -1) return -1;
            }
        }
        return u;
    }

    int lca(int u, int v){
        if(lvl[u] < lvl[v]) swap(u, v);

        u = kth(u, lvl[u] - lvl[v]);
        if(u == v) return u;

        for(int i = LOG-1; i >= 0; i--){
            if(parent[u][i] != parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }

    int distBetween(int u, int v){
        int L = lca(u, v);
        return dist[u] + dist[v] - 2*dist[L];
    }
};

const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> minimumWeight(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        LCA bl(n);

        for(auto &e : edges){
            bl.addEdge(e[0], e[1], e[2]);
        }

        bl.dfs(0);
        bl.build();

        vector<int> ans(queries.size(), -1);

        for(int i = 0; i < queries.size(); i++){
            int src1 = queries[i][0];
            int src2 = queries[i][1];
            int dest = queries[i][2];

            ans[i] = bl.distBetween(0, src1) + bl.distBetween(0, src2) + bl.distBetween(0, dest) - bl.distBetween(0, bl.lca(src1, src2)) - bl.distBetween(0, bl.lca(src2, dest)) - bl.distBetween(0, bl.lca(src1, dest));
        }
        return ans;
    }
};