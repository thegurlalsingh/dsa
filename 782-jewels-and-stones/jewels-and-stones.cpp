class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_map<char, int> s;
        for(int i = 0; i < stones.size(); i++){
            s[stones[i]]++;
        }
        int count = 0;
        for(int i = 0; i < jewels.size(); i++){
            if(s.find(jewels[i]) != s.end()){
                count += s[jewels[i]];
            }
        }
        return count;
    }
};