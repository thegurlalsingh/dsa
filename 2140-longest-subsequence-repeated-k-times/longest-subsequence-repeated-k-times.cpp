class Solution {
private:
    bool occursKTimes(string& s, string& sub, int k) {
        int i = 0, count = 0;
        while (i < s.length() && count < k) {
            int j = 0;
            for (int x = i; x < s.length(); x++) {
                if (s[x] == sub[j]) j++;
                if (j == sub.length()) {
                    count++;
                    i = x + 1;
                    break;
                }
            }
            if (j < sub.length()) {
                break;
            }
        }
        return count >= k;
    }

    void generateSubsequences(map<char, int>& freqMap, string& current, int maxLen, vector<string>& result) {
        if (!current.empty()) {
            result.push_back(current);
        }

        if (current.size() >= maxLen) return;

        for (auto& [ch, count] : freqMap) {
            if (count > 0) {
                freqMap[ch]--;
                current.push_back(ch);
                generateSubsequences(freqMap, current, maxLen, result);
                current.pop_back();
                freqMap[ch]++;
            }
        }
    }

public:
    string longestSubsequenceRepeatedK(string s, int k) {
        unordered_map<char, int> m;
        for (char ch : s) {
            m[ch]++;
        }

        for (auto it = m.begin(); it != m.end(); ) {
            if (it->second < k) {
                it = m.erase(it);
            } else {
                ++it;
            }
        }

        if (m.empty()) {
            return "";
        }

        map<char, int> freqMap;
        for (auto& [ch, freq] : m) {
            freqMap[ch] = freq / k;
        }

        vector<string> subsequences;
        string temp = "";
        generateSubsequences(freqMap, temp, 7, subsequences);

        sort(subsequences.begin(), subsequences.end(), [](const string& a, const string& b) {
            return a.size() > b.size() || (a.size() == b.size() && a > b);
        });

        for (string& sub : subsequences) {
            if (occursKTimes(s, sub, k)) {
                return sub;
            }
        }

        return "";
    }
};
