class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int score = 0;
        string a = (x > y) ? "ab" : "ba";
        int first = max(x, y);
        int second = min(x, y);
        string b = (a == "ab") ? "ba" : "ab";

        string temp = "";
        for (char ch : s) {
            temp += ch;
            int len = temp.size();
            if (len >= 2 && temp.substr(len - 2) == a) {
                temp.pop_back();
                temp.pop_back();
                score += first;
            }
        }

        string finalStr = "";
        for (char ch : temp) {
            finalStr += ch;
            int len = finalStr.size();
            if (len >= 2 && finalStr.substr(len - 2) == b) {
                finalStr.pop_back();
                finalStr.pop_back();
                score += second;
            }
        }

        return score;
    }
};
