class Solution {
public:
    vector<vector<int>> adjList;
    vector<vector<vector<int>>> dp;

    int findPalindromeWithCenter(int node1, int node2, int mask, string& label) {
        if(dp[node1][node2][mask]!=-1) return dp[node1][node2][mask];
        int ans=0;
        for(auto child : adjList[node1]) {
            if((mask>>child)&1) continue;
            for(auto child2 : adjList[node2]) {
                if(child == child2 || (mask>>child2)&1) continue;
                if(label[child]==label[child2]) {
                    ans = max(ans, 2+findPalindromeWithCenter(child,child2,mask|(1<<child)|(1<<child2),label));
                }
            }
        }
        return dp[node1][node2][mask] = ans;
    }

    int maxLen(int n, vector<vector<int>>& edges, string label) {
        adjList.resize(n);
        dp.resize(n+1,vector<vector<int>>(n+1,vector<int>(1<<14,-1)));
        for(auto edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int ans =1;

        for(int i=0;i<n;i++) {
            //for odd length
            ans = max(ans, 1+findPalindromeWithCenter(i,i,0|1<<i,label));
            //cout<<i<<" "<<ans<<endl;

            //for even length
            for(auto j : adjList[i]) {
                if(label[i]==label[j]) {
                    ans = max(ans, 2+ findPalindromeWithCenter(i,j,0|1<<i|1<<j,label));
                }
            }
            //cout<<i<<" "<<ans<<endl;
        }

        return ans;
    }
};