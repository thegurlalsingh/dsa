class Solution {
    // int f(int x){
    //     return x*(x - 1)/2;
    // }
public:
    int prefixConnected(vector<string>& words, int k) {
        int sum = 0;
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++){
            if(words[i].length() >= k){
                string temp = words[i].substr(0, k);
                mp[temp]++;
            }
        }
        for(auto& p : mp){
            if(p.second > 1){
                sum++;
            }
        }
        return sum;
    }
};