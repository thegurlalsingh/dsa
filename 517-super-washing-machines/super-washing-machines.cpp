class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        int sum = accumulate(machines.begin(), machines.end(), 0);
        int n = machines.size();
        if(sum % n != 0) return -1;
        int target = sum / n;
        
        int res = 0;
        int cum = 0; // cumulative imbalance
        for(int dresses : machines){
            int diff = dresses - target;
            cum += diff;
            res = max(res, max(abs(cum), diff)); 
        }
        return res;
    }
};
