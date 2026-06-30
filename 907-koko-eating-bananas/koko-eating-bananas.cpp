class Solution {
    bool helper(vector<int>& piles, int h, long long mid){
        long long m = 0;
        for(int i = 0; i < piles.size(); i++){
            m += (piles[i] + mid - 1) / mid;
        }
        return m <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans = 0;
        long long i = 1;
        long long j = 1e10;
        while(i <= j){
            long long mid = (i + j) / 2;
            if(helper(piles, h, mid)){
                ans = mid;
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return ans;
    }
};