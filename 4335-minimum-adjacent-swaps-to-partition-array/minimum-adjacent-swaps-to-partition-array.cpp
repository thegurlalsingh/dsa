class Solution {
public:
    static constexpr int MOD = 1000000007;

    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        long long answer = 0;
        long long middleCount = 0;
        long long greaterCount = 0;

        for (int value : nums) {
            if (value < a) {
                answer = (answer + middleCount + greaterCount) % MOD;
            } else if (value <= b) {
                answer = (answer + greaterCount) % MOD;
                middleCount++;
            } else {
                greaterCount++;
            }
        }

        return answer;
    }
};