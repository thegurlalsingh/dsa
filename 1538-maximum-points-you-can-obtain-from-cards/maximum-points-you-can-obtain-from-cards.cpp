class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int sum = 0;
        for(int i = 0; i < n; i++) sum += cardPoints[i];

        int arr = n - k;
        if(arr == 0) return sum; // edge case: take all cards

        int i = 0, j = 0;
        int minSum = INT_MAX;
        int s = 0;

        while(j < n){
            s += cardPoints[j];
            if(j - i + 1 == arr){
                minSum = min(minSum, s);
                s -= cardPoints[i];
                i++;
            }
            j++;
        }

        return sum - minSum;
    }
};
