class Solution {
public:
    int solve(vector<int>&arr , int prev , int cur , int val , vector<vector<int>>&dp){
        int n = arr.size() ; 
        if(cur>=n)
        return 0 ; 

        if(dp[prev+1][cur] != -1)
        return dp[prev+1][cur] ; 

        val = min(val , arr[cur]) ; 
        int ans = val*(cur-prev) ; 
        ans = max(ans , solve(arr , prev , cur+1 , val , dp)) ; 
        ans = max(ans , solve(arr , cur , cur+1 , INT_MAX , dp)) ;
        return dp[prev+1][cur] = ans ; 
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ; 
        vector<vector<int>>vtr(n , vector<int>(m , 0)) ; 
        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<m; j++){
                if(i == 0){
                    if(matrix[i][j] == '1')
                    vtr[i][j] = 1 ; 
                }else{
                    if(matrix[i][j] == '1')
                    vtr[i][j] = 1 + vtr[i-1][j] ; 
                }
            }
        }
        int ans = 0 ; 
        for(int i = 0 ; i<n ; i++){
            vector<vector<int>>dp(m+1 , vector<int>(m , -1)) ; 
            ans = max(ans , solve(vtr[i] , -1 , 0 , INT_MAX , dp)) ; 
        }
        return ans ; 
    }
};