class Solution {
private:
    int findParent(int u, vector<int> &p){
        if(u==p[u])return u;
        return p[u]=findParent(p[u],p);
    }
    void Union(int a,int b, vector<int> &s, vector<int> &p){
        int u=findParent(a,p);
        int v=findParent(b,p);
        if(s[u]>s[v]){
            p[v]=u;
            s[u]+=s[v];
        }else{
            p[u]=v;
            s[v]+=s[u];
        }
    }
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size()+1;

        vector<int> indegree(n,0);
        vector<vector<int>> adj(n);

        vector<int> p(n);
        for(int i=0;i<n;i++){
            p[i]=i;
        }
        vector<int> s(n,1);

        int condn=-1;
        for(auto i:edges){
            indegree[i[1]]++;
            if(indegree[i[1]]>1)condn=i[1];
            adj[i[1]].push_back(i[0]);
        }
        vector<int> ans;
        if(condn==-1){
            for(auto i:edges){
                int u=i[0];
                int v=i[1];
                int pu=findParent(u,p);
                int pv=findParent(v,p);
                if(pu!=pv){
                    Union(pu,pv,s,p);
                }else{
                    ans={u,v};
                    break;
                }
            }
        }else{
            for(auto j:edges){
                if(j[1]==condn)continue;
                int u=j[0];
                int v=j[1];
                int pu=findParent(u,p);
                int pv=findParent(v,p);
                Union(pu,pv,s,p);
            }
            for(auto i:adj[condn]){
                int u=i;
                int v=condn;
                int pu=findParent(u,p);
                int pv=findParent(v,p);
                if(pu!=pv){
                    Union(pu,pv,s,p);
                }else{
                    ans={u,v};
                    break;
                }
            }
        }
        return ans;
    }
};