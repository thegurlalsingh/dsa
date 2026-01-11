struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int x : v) {
            hash = hash * 31 + x; 
        }
        return hash;
    }
};

class Solution {
    vector<int> ascii(string& s){ 
        vector<int> diff; 
        if(s.size() == 1){ 
            diff.push_back((int)s[0]); 
            return diff; 
            } 
            for(int i = 1; i < s.size(); i++){ 
                int d = s[i] - s[i - 1]; 
                if(d < 0){ 
                    d += 26; 
                } 
                diff.push_back(d); 
            } 
            return diff; 
        }
public:
    long long countPairs(vector<string>& words) {
        if(words[0].size() == 1){
            long long n = words.size();
            return n * (n - 1) / 2;  
        }
        unordered_map<vector<int>, long long, VectorHash> freq;
        long long count = 0;

        for(int i = 0; i < words.size(); i++){
            vector<int> temp = ascii(words[i]);
            count += freq[temp];  
            freq[temp]++;
        }

        return count;
    }
};
