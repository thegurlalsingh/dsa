class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 0; 

        for (char c : s) {
            if (!result.empty() && result.back() == c) {
                count++;
            } else {
                count = 1; 
            }
            if (count < 3) {
                result += c;
            }
        }

        return result; 
    }
};
