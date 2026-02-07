class Solution {
public:
    long long lastInteger(long long n) {
        if(n == 1){
            return 1;
        }
        long long i = 1;
        bool left = true;
        long long remaining = n;
        long long ans = 1;
        while(remaining > 1){
            if((remaining % 2 == 0) && (left == false)){
                ans += i;
            }
            i = i * 2;
            //moving head
            remaining = ceil(remaining / 2.0);
            left = !left;
        }
        return ans;
    }
};