class Solution {
private:
    bool check(string& s, int k, string& target) {
        return s.find(target) != string::npos;
    }
public: 
    int minimumRecolors(string blocks, int k) {
        string target(k, 'B');
        if(check(blocks, k, target)){
            return 0;
        }
        int countW = 0, minCount = INT_MAX;
        for (int i = 0; i < blocks.size(); i++) {
            if (blocks[i] == 'W') {
                countW++;
            }
            if (i >= k - 1) {  
                minCount = min(minCount, countW);
                if (blocks[i - k + 1] == 'W') {
                    countW--;
                }
            }
        }
        return minCount;
    }
};