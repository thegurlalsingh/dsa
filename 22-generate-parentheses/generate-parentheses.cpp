class Solution {
private:
    void generateParentheses(int open, int close, string current, vector<string>& result) {
        if (open == 0 && close == 0) {
            result.push_back(current);
            return;
        }

        if (open > 0) {
            generateParentheses(open - 1, close, current + "(", result);
        }

        if (close > open) {
            generateParentheses(open, close - 1, current + ")", result);
        }
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generateParentheses(n, n, "", result);
        return result;
    }
};
