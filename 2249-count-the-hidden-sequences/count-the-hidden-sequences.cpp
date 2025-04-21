class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long minPrefix = 0, maxPrefix = 0, prefix = 0;

        for (int diff : differences) {
            prefix += diff;
            minPrefix = min(minPrefix, prefix);
            maxPrefix = max(maxPrefix, prefix);
        }

        long minStart = lower - minPrefix;
        long maxStart = upper - maxPrefix;

        return max(0L, maxStart - minStart + 1);
    }
};
