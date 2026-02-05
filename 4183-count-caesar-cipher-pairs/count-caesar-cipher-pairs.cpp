class Solution {
    long long f(long long x){
        return (x * (x - 1)) / 2;
    }

    long long hashVector(const vector<int>& v) {
        const long long P = 31;
        const long long M = 1000000007;

        long long h = 0;
        long long power = 1;

        for (int x : v) {
            h = (h + x * power) % M;
            power = (power * P) % M;
        }
        return h;
    }

public:
    long long countPairs(vector<string>& words) {
        unordered_map<long long, long long> mp;

        for (int i = 0; i < words.size(); i++) {
            vector<int> temp;

            for (int j = 1; j < words[i].size(); j++) {
                int x = (words[i][j] - words[i][j - 1] + 26) % 26;
                temp.push_back(x);
            }

            long long hash = hashVector(temp);
            mp[hash]++;
        }

        long long count = 0;
        for (auto& p : mp) {
            if (p.second > 1) {
                count += f(p.second);
            }
        }
        return count;
    }
};
