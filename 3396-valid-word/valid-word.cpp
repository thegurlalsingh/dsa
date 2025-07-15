class Solution {
private:
    bool cond1(string& s) {
        return s.length() >= 3;
    }

    bool cond2(string& s) {
        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i]) && !isalpha(s[i])) {
                return false;
            }
        }
        return true;
    }

    bool cond3(string& s) {
        for (char c : s) {
            if (string("aeiouAEIOU").find(c) != string::npos) {
                return true; 
            }
        }
        return false;
    }

    bool cond4(string& s) {
        for (char c : s) {
            char lowerC = tolower(c);  
            if (isalpha(lowerC) && lowerC != 'a' && lowerC != 'e' && lowerC != 'i' && lowerC != 'o' && lowerC != 'u') {
                return true;  
            }
        }
        return false;
    }

public:
    bool isValid(string& word) {
        return cond1(word) && cond2(word) && cond3(word) && cond4(word);
    }
};

