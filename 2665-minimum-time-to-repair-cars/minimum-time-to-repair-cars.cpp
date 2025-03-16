class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long maximumTime = 1LL * cars * cars * (*min_element(ranks.begin(), ranks.end())); 
        long long left = 1, right = maximumTime, ans = maximumTime;

        while (left <= right) {  
            long long mid = left + (right - left) / 2;
            long long s = 0;
            
            for (int rank : ranks) {
                s += floor(sqrt(mid / rank)); 
            }

            if (s >= cars) {
                ans = mid;
                right = mid - 1; 
            } else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
