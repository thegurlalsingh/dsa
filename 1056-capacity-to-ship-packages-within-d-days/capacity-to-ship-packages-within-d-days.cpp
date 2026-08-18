class Solution {
    bool helper(vector<int>& weights, int days, long long mid){
        long long total_days = 1;
        long long temp = 0;
        for (int i = 0; i < weights.size(); i++) {
            if (temp + weights[i] <= mid) {
                temp += weights[i];
            }
            else {
                total_days++;
                temp = weights[i];
            }
        }
        return total_days <= days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        long long ans = 0;
        while(low <= high){
            long long mid = (low + high) / 2;
            if(helper(weights, days, mid)){ 
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
};