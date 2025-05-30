class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        if (words.empty()) return {};
        
        vector<int> indices;
        indices.push_back(0); 
        int prevGroup = groups[0];

        for (int i = 1; i < groups.size(); i++) {
            if (groups[i] != prevGroup) {
                indices.push_back(i);
                prevGroup = groups[i];
            }
        }

        vector<string> result;
        for (int idx : indices) {
            result.push_back(words[idx]);
        }

        return result;
    }
};
