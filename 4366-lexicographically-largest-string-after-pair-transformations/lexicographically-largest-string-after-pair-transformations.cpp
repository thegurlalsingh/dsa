class Solution {
    vector<int> solve(int n) {
        vector<int> ans;
        while (n > 0) {
            int p = 1;
            int power = 0;
            while (p * 2 <= n) {
                p *= 2;
                power++;
            }
            ans.push_back(power);
            n -= p;
        }
        return ans;
    }

public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> ans(nums.size(), "\n");
        for(int i = 0; i < nums.size(); i++){
            vector<int> options = solve(nums[i]);
            string t = "";
            for(int j = 0; j < options.size(); j++){
                char c = 97 + options[j];
                t += c;
                if(t.back() == '{'){
                    t.pop_back();
                    t += "zz";
                }
            }
            ans[i] = t;
        }
        return ans;
    }
};