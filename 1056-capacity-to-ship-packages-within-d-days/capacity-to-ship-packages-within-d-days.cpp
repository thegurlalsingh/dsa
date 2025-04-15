class Solution {
private:
    bool check(vector<int>& weights, int m, int capacity){
        int days = 1;       
        int currentLoad = 0;

        for (int w : weights) {
            if (currentLoad + w > capacity) {
                days++;            
                currentLoad = w;   
            } else {
                currentLoad += w;
            }
        }

        return days <= m;
    }

public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;

        while(low <= high){
            int mid = (high + low) / 2;
            if(check(weights, days, mid)){
                ans = mid;           
                high = mid - 1;      
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};
