class Solution {
public:
    bool judgeSquareSum(int c) {
        bool found = false;
        unordered_map<int,int> mp;
        for(long long i = 0; i * i <= c; i++){
            mp[i*i] = 1;
        }
        for(long long i = 0; i * i <= c; i++){
            long long diff = c - (i * i);
            if(mp.find(diff) != mp.end()){
                return true;
            }
        }
        return false;
    }
};