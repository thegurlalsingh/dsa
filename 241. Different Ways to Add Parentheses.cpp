class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        vector<int> results;

        for (size_t i = 0; i < expression.size(); ++i) {
            char ch = expression[i];
            if (ch == '+' || ch == '-' || ch == '*') {
                string leftPart = expression.substr(0, i);
                string rightPart = expression.substr(i + 1);
                vector<int> leftResults = diffWaysToCompute(leftPart);
                vector<int> rightResults = diffWaysToCompute(rightPart);
                for (int left : leftResults) {
                    for (int right : rightResults) {
                        if (ch == '+') {
                            results.push_back(left + right);
                        } else if (ch == '-') {
                            results.push_back(left - right);
                        } else if (ch == '*') {
                            results.push_back(left * right);
                        }
                    }
                }
            }
        }

        if (results.empty()) {
            results.push_back(stoi(expression));
        }

        return results;
    }
};