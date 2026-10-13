class Solution {
public:
    long long maxValue(vector<int>& nums) {
        int n = nums.size();

        long long ans = 1e18; // maximum sum means minimum value of improvement or more negative value from rotation for maximum improvement -> thats why i took here 1e18
        long long s = 0; // this is running alternating sum

        // in prefix calculation, choosing 0 means empty prefix, thats why in starting even length prefix ie 0 length prefix is 0 while odd length prefix is not initialized thus int_min
        long long e = 0; // alternating sum of even length prefix
        long long o = -1e18; // alternating sum of odd length prefix

        for (int i = 0; i < n; i++) {

            // Alternating prefix sum
            s += (i % 2 == 0 ? nums[i] : -nums[i]);

            if ((i + 1) % 2 == 0) { // checking i + 1 because if the current index is i, the prefix contains i + 1 elements.
                ans = min(s - e, ans); // this is basically prefix alternating sum formula -> current - prev (best)
                e = max(e, s); // calculating max sum because we want to remember the largest previous prefix sum for future comparisons.
            }
            else {
                ans = min(s - o, ans);
                o = max(o, s);
            }
        }

        // +a-b+c-d -> After rotation, the elements shift one position to the left, so their signs flip. -> +b-c+d-a
        s -= (2 * min(0LL, ans)); // this comes from a formula

        return s;
    }
};