class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) return 1; // only 0

        int ans = 10;  // for n = 1 (0 to 9)
        int uniqueDigits = 9; // first digit has 9 options (1–9)
        int available = 9;    // remaining digits available

        for (int i = 2; i <= n && available > 0; i++) {
            uniqueDigits *= available; // multiply with remaining options
            ans += uniqueDigits;       // add all unique i-digit numbers
            available--;               // next time, one fewer digit left
        }

        return ans;
    }
};
