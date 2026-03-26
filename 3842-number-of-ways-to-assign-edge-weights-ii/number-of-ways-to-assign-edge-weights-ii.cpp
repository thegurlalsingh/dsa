#define ll long long

struct BinaryLifting {
    int n, LOG;
    vector<vector<int>> parent;
    vector<int> lvl;
    vector<vector<int>> adj;

    BinaryLifting(int n){
        this->n = n;
        LOG = log2(n) + 1;

        parent.assign(n, vector<int>(LOG, -1));
        lvl.assign(n, 0);
        adj.resize(n);
    }

    void addEdge(int u, int v){
        adj[u - 1].push_back(v - 1);
        adj[v - 1].push_back(u - 1);
    }

    void dfs(int root = 0){
        stack<tuple<int,int,int>> st;
        st.push({root, 0, -1});

        while(!st.empty()){
            auto [node, level, par] = st.top();
            st.pop();

            lvl[node] = level;
            parent[node][0] = par;

            for(int child : adj[node]){
                if(child != par){
                    st.push({child, level+1, node});
                }
            }
        }
    }

    void build(){
        for(int j = 1; j < LOG; j++){
            for(int i = 0; i < n; i++){
                if(parent[i][j-1] != -1){
                    parent[i][j] = parent[parent[i][j-1]][j-1];
                }
            }
        }
    }

    // 🔥 optimized lifting (log2 jump)
    int lift(int u, int k){
        while(k > 0){
            int jump = log2(k);
            u = parent[u][jump];
            if(u == -1) return -1;
            k -= (1 << jump);
        }
        return u;
    }

    int lca(int u, int v){
        if(lvl[u] < lvl[v]) swap(u, v);

        u = lift(u, lvl[u] - lvl[v]);
        if(u == v) return u;

        for(int i = LOG-1; i >= 0; i--){
            if(parent[u][i] != parent[v][i]){
                u = parent[u][i];
                v = parent[v][i];
            }
        }
        return parent[u][0];
    }

    int dist(int u, int v){
        int L = lca(u, v);
        return lvl[u] + lvl[v] - 2 * lvl[L];
    }
};

const int MOD = 1e9 + 7;

class Solution {
public:
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;

        BinaryLifting bl(n);

        for(auto &e : edges){
            bl.addEdge(e[0], e[1]);
        }

        bl.dfs(0);
        bl.build();

        // 🔥 precompute powers
        vector<int> pow2(n+1);
        pow2[0] = 1;
        for(int i = 1; i <= n; i++){
            pow2[i] = (pow2[i-1] * 2LL) % MOD;
        }

        vector<int> ans;

        for(auto &q : queries){
            int u = q[0] - 1, v = q[1] - 1;

            int d = bl.dist(u, v);

            ans.push_back(d == 0 ? 0 : pow2[d-1]);
        }

        return ans;
    }
};