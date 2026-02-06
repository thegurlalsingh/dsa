class Solution {
public:
    int minAllOneMultiple(int k) {
        __int128 r = 0;
        int len = 0;

        for (int i = 1; i <= 100000; i++) {
            r = r * 10 + 1;
            r %= k;          
            len++;

            if (r == 0)
                return len;
        }
        return -1;
    }
};
