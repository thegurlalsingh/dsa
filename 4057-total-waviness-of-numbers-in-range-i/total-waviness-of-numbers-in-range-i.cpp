class Solution {
    int helper(int num){
        string s = to_string(num);
        if(s.length() < 3){
            return 0;
        }
        int count = 0;
        for(int i = 1; i < s.length() - 1; i++){
            if((s[i] - '0' > s[i - 1] - '0' && s[i] - '0' > s[i + 1] - '0') || 
            ((s[i] - '0' < s[i - 1] - '0' && s[i] - '0' < s[i + 1] - '0'))){
                count++;
            }
        }
        return count;
    }
public:
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        for(int i = num1; i <= num2; i++){
            int x = helper(i);
            if(x > 0){
                waviness += x;
            }
        }
        return waviness;
    }
};