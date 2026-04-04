class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        
        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'a']++;
        }

        unordered_set<int> used;
        int deletions = 0;

        for (int i = 0; i < 26; i++) {
            int f = freq[i];

            while (f > 0 && used.count(f)) {
                f--;
                deletions++;
            }

            if (f > 0) used.insert(f);
        }

        return deletions;
    }
};