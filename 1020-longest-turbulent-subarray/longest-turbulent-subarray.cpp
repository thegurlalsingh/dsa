class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n = arr.size();
        if (n == 1) return 1;

        int inc = 1, dec = 1, ans = 1;

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) {
                inc = dec + 1;  // previous must have been a down
                dec = 1;        // reset down
            } 
            else if (arr[i] < arr[i - 1]) {
                dec = inc + 1;  // previous must have been an up
                inc = 1;        // reset up
            } 
            else {
                inc = dec = 1;  // equal elements break turbulence
            }
            ans = max(ans, max(inc, dec));
        }

        return ans;
    }
};
