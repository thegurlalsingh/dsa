class Solution {
    long long countDigits(long long b) {
        if(b < 0) {
            return 0;
        }

        long long ans = 9;  

        long long start = 1;

        while(start <= b) {
            long long end = min(b, start * 10 - 1);

            long long blocks = end - start + 1;
            long long digitsPerBlock = 10LL * to_string(10 * start).size();

            ans += blocks * digitsPerBlock;

            start *= 10;
        }

        return ans;
    }
public:
    int kthDigit(long long k) {
        long long low = 1; long long high = 1e14;
        long long ans = 0;
        while(low <= high){
            long long mid = (low + high) / 2;
            long long remaining = k - countDigits(mid - 1);
            if(remaining <= 0){
                high = mid - 1;
            }
            else{
                ans = mid;
                low = mid + 1;
            }
        }

        long long digitsBeforeCurrentBlock = countDigits(ans - 1);
        long long newK = k - digitsBeforeCurrentBlock;
        if(ans == 0) {
            for(long long x = 1; x <= 9; x++) {
                string s = to_string(x);

                if(newK <= s.size())
                    return s[newK - 1] - '0';

                newK -= s.size();
            }
        }
        if(ans % 2 == 0){
            for(long long x = 10 * ans; x <= (10 * ans) + 9; x++) {
                string s = to_string(x);

                if(newK <= s.size()) {
                    return s[newK - 1] - '0';
                }

                newK -= s.size();
            }
        }
        else{
            for(long long x = (10 * ans) + 9; x >= 10 * ans; x--) {
                string s = to_string(x);

                if(newK <= s.size()) {
                    return s[newK - 1] - '0';
                }

                newK -= s.size();
            }
        }

        return -1;
    }
};