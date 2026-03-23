#define ll long long
const int MAXN = 1e5 + 5;

int parent[MAXN][20];
ll dp[MAXN];
int lvl[MAXN];

class Solution {
public:
    void dfs(int root, int level, ll sum, int par, vector<vector<pair<int, int>>> & adj){
        stack<tuple<int, int, ll, int>> st;
        st.push({root, 0, 0LL, -1});

        while (!st.empty()) {
            auto [node, level, sum, par] = st.top();
            st.pop();

            dp[node] = sum;
            lvl[node] = level;
            parent[node][0] = par;

            for (auto &[child, w] : adj[node]) {
                if (child != par) {
                    st.push({child, level + 1, sum + w, node});
                }
            }
        }
    }
    int findPar(int u, int k){
        int par = u;
        for(int i = 19; i>=0; i--){
            if((1<<i)&k){
                int x = 1<<i;
                par = parent[u][i];
                u = par;
                if(par == -1)return 0;
                k -= x;
            }
        }
        return par;
    }
    int lca(int u, int v){
        if(lvl[u] > lvl[v])swap(u, v);
        int s = lvl[u], e = lvl[v];
        int x = findPar(v, e-s);
        if(x == u)return u;
        v = x;
        e = s;
        s = 0;
        int ans = 0;
        while(s <= e){
            int mid = s+(e-s)/2;
            int paru = findPar(u, mid);
            int parv = findPar(v, mid);
            if(paru == parv){
                ans = paru;
                e = mid-1;
            }
            else s = mid+1;
        }
        return ans;
    }
    int bsearch(int u, int v, bool flag, ll tot, ll val){
        int s = 0, e = lvl[v]-lvl[u];
        int ans = u;
        while(s <= e){
            int mid = s+(e-s)/2;
            int par = findPar(v, mid);
            ll sum = flag ? dp[v]-dp[par] : dp[par]-dp[u]+val;
            if(sum >= (tot/2)+(tot%2)){
                ans = par;
                if(flag)e = mid-1;
                else s = mid+1;
            }
            else{
                if(flag) s = mid+1;
                else e = mid-1;
            }
        }
        return ans;
    }
    vector<int> findMedian(int n, vector<vector<int>>& edges, vector<vector<int>>& q) {
        vector<vector<pair<int, int>>> adj(n);
        for(auto it : edges){
            int u = it[0], v = it[1], w = it[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w});
        }

        // vector<ll> dp(n);
        // vector<int> lvl(n);
        // vector<vector<int>> parent(n, vector<int> (20, -1));
        dfs(0, 0, 0, -1, adj);
        for(int i = 1; i<20; i++){
            for(int j = 0; j<n; j++){
                int par = parent[j][i-1];
                if(par != -1)parent[j][i] = parent[par][i-1];
            }
        }
        vector<int> ans;
        for(auto it : q){
            int u = it[0], v = it[1];
            int node;
            int commonPar = lca(u, v);
            ll tot = dp[u]+dp[v]-2*dp[commonPar];
            if(dp[v]-dp[commonPar] >= tot/2+(tot%2)){
                node = bsearch(commonPar, v, 0, tot, dp[u]-dp[commonPar]);
            }
            else node = bsearch(commonPar, u, 1, tot, 0);
            ans.push_back(node);
        }
        return ans;
    }
};