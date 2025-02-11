class Solution {
private:
    string removeSubstring(std::string str, const std::string &sub) {
        int pos;
        while ((pos = str.find(sub)) != string::npos) { 
            str.erase(pos, sub.length()); 
        }
        return str;
    }
public:
    string removeOccurrences(string s, string part) {
        string result = removeSubstring(s, part);
        return result;
    }
};