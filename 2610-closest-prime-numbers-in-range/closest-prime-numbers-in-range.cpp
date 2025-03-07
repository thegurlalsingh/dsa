class Solution {
private:
    bool isPrime(int n) {
        if (n < 2) {
            return false;
        }
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
public:
    vector<int> closestPrimes(int left, int right) {   
        vector<int> arr;
        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                arr.push_back(i);
            }
        }
        if(arr.size() < 2){
            return {-1, -1};
        }
        int minDiff = INT_MAX;
        int num1 = 0;
        int num2 = 0;
        for(int i = 0; i < arr.size() - 1; i++){
            if(abs(arr[i] - arr[i + 1]) < minDiff){
                minDiff = abs(arr[i] - arr[i + 1]);
                num1 = arr[i];
                num2 = arr[i+1];
            }
        }
        return {num1, num2};
    }
};