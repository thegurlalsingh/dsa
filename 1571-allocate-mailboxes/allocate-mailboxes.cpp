class Solution {
    int solve(vector<int>& houses, int k, int currSt, int idx, vector<int>& prefixSum, unordered_map<string, int>& dp){
        //denoting that we have allocated mailboxes for all houses
        if( idx >= houses.size() ){

            //it may be possible that by continuosly extending group 
            //we have reached the end but still have some mailboxes
            //left to allocate, thus it a check fot that condition

            if( k == 0 )
                return 0;
            //return 0 only if no more mailboxes left, as now there
            //is no more further cost to add
            return INT_MAX;
        }

       //if the number of mailboxes left has fallen to <=0 without
        //reaching end, return
        if( k <= 0 )
            return INT_MAX;

        //key for memo
        string key = to_string(currSt) + "," + to_string(idx) + "," + to_string(k);

        //if this state has already been calculated return
        if( dp.count(key) )
            return dp[key];
        
        //calculate median, lc, rc, leftSum, rightSum
        int mid = (currSt + idx)/2, lc = mid - currSt, rc = idx - mid;
        long leftSum, rightSum, dist, opn, close;

        //using prefixSum techniquq
        leftSum = prefixSum[mid] - prefixSum[currSt];
        rightSum = prefixSum[idx+1] - prefixSum[mid+1];

        //using explained formula
        dist = houses[mid]*lc - leftSum + rightSum - houses[mid]*rc;

        //case when we close the group at this idx
        close = dist + solve(houses, k-1, idx+1, idx+1, prefixSum, dp);
        
        //case when we extend and hope further house to close the
        //group and calculate the dist
        opn = solve(houses, k, currSt, idx + 1, prefixSum, dp);

        //store and return the minimum of two choices
        dp[key] = min(opn, close);
        return dp[key];        
    }

public:
    int minDistance(vector<int>& houses, int k) {
        int n = houses.size();

        //if there are more or equal mailboxes no distance 
        //we will simply place a mailbox in front of each house
        if( k >= n )
            return 0;


        //sort the houses to use the median technique for optimal dist
        sort(houses.begin(), houses.end());

        vector<int> prefixSum(n+1, 0);
        prefixSum[0] = 0;

        //calculate prefixSum
        for(int i = 1; i <= n; i++){
            prefixSum[i] = houses[i-1] + prefixSum[i-1];
        }

        unordered_map<string, int> dp;

        return solve(houses, k, 0, 0, prefixSum, dp);
    }
};