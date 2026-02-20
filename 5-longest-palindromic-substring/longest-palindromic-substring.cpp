class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int n = s.size();
        int start = 0;
        int end = 0;

        for (int center = 0; center < 2 * n - 1; center++) {
            int left = center / 2; int right = left + center % 2;

            int len = expandAroundCenter(s, left, right);

            if (len > end - start + 1) {
                start = (center - len + 1) / 2;
                end = start + len - 1;
            }
        }

        return s.substr(start, end - start + 1);        
    }

private:
    int expandAroundCenter(string s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1;
    }    
};