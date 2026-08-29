class Solution {
    
public:
    string largestNumber(vector<int>& nums) { 
        vector<string> str;
        for(int i = 0; i < nums.size(); i++){
            str.push_back(to_string(nums[i]));
        }
        sort(str.begin(), str.end(), [](auto &a, auto &b) {
            return a + b > b + a;
        });
        string s = "";
        for(int i = 0; i < str.size(); i++){
            s += str[i];
        }
        int start = 0;
        for(; start < s.size(); start++){
            if(s[start] != '0'){
                break;
            }
        }
        return start == s.size() ? "0" : s.substr(start);
    }
};