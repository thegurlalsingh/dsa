class Solution {
    __int128 howManyY(__int128 x, __int128 y) {
        return (x + y - 1) / y;   
    }

    bool calculate(__int128 mid, vector<int>& nums) {
        __int128 count = 0;
        for (int x : nums) {
            count += howManyY(x, mid);
        }
        return count <= (__int128)mid * (__int128)mid;
    }

public:
    int minimumK(vector<int>& nums) {
        __int128 sum = 0;
        for (int x : nums) sum += x;

        __int128 ans = sum;
        __int128 low = 1, high = sum;

        while (low <= high) {
            __int128 mid = low + (high - low) / 2;

            if (calculate(mid, nums)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return (int)ans;
    }
};
