class Solution {
    private:
    int countSteps(int n, long long curr, long long next) {
        int steps = 0;
        while (curr <= n) {
            steps += min((long long)n + 1, next) - curr;
            curr *= 10;
            next *= 10;
        }
        return steps;
    }
public:
    int findKthNumber(int n, int k) {
       int curr = 1; 
        k--;
        
        while (k > 0) {
            int steps = countSteps(n, curr, curr + 1); 
            if (steps <= k) {
                curr += 1;
                k -= steps;
            } else {
                curr *= 10;
                k -= 1;
            }
        }
        return curr;
    }
};