class Solution {
    bool check(int mid, vector<int>& piles, int h){
        long long hour = 0;
        for(int i = 0; i < piles.size(); i++){
            hour += (piles[i] + mid - 1) / mid;
        }
        return hour <= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1; int j = 1e9;
        int ans = 0;
        while(i <= j){
            int mid = (i + j)/2;
            if(check(mid, piles, h)){
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