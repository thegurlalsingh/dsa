class Solution {
public:
    int countMagicalPairs(string s) {
        int ans = 0;

        for(int j = 0; j < s.size() - 1; j++){
            unordered_map<char, int> left;
            unordered_map<int, int> freq;
            int distinct = 0;

            for(int i = j; i >= 0; i--){
                if(left.find(s[i]) == left.end()){
                    left[s[i]]++;
                    distinct++;
                }
                freq[distinct]++;
            }

            unordered_map<char, int> right;
            distinct = 0;

            for(int k = j + 1; k < s.size(); k++){
                if(right.find(s[k]) == right.end()){
                    right[s[k]]++;
                    distinct++;
                }
                ans += freq[distinct];
            }
        }

        return ans;
    }
};