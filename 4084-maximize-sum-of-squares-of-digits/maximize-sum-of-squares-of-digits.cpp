class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) {
            return "";
        }
        vector<int> d;
        int i = 9;
        while(sum > 0){
            while(sum >= i){
                d.push_back(i);
                sum -= i;
            }
            i--;
        }

        string ans = "";
        for(int i = 0 ; i < d.size(); i++){
            ans += to_string(d[i]);
        }

        while(ans.size() < num){
            ans += "0";
        }

        return ans;
    }
};