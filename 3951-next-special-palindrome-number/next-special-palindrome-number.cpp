class Solution {

    vector<string> generatePermutations(string s){
        vector<string> res;
        sort(s.begin(), s.end());
        do{
            res.push_back(s);
        }while(next_permutation(s.begin(), s.end()));
        return res;
    }

    void get(unordered_map<int, set<long long>>& mp){

        for(int mask = 1; mask < (1<<9); mask++){

            vector<int> digits;
            int len = 0;

            for(int d = 1; d <= 9; d++){
                if(mask & (1<<(d-1))){
                    digits.push_back(d);
                    len += d;
                }
            }

            if(len > 17) continue;

            int odd = 0;
            for(int d : digits) if(d % 2) odd++;

            if(len % 2 == 0 && odd > 0) continue;
            if(len % 2 == 1 && odd != 1) continue;

            string half = "";
            char mid = '#';

            for(int d : digits){

                for(int i = 0; i < d/2; i++)
                    half += char('0' + d);

                if(d % 2)
                    mid = char('0' + d);
            }

            auto perms = generatePermutations(half);

            for(string p : perms){

                string r = p;
                reverse(r.begin(), r.end());

                string num;

                if(mid != '#')
                    num = p + mid + r;
                else
                    num = p + r;

                mp[len].insert(stoll(num));
            }
        }
    }

public:
    long long specialPalindrome(long long n) {

        unordered_map<int, set<long long>> mp;

        get(mp);

        string str = to_string(n);
        int len = str.size();

        for(long long p : mp[len]){
            if(p > n) return p;
        }

        return *mp[len+1].begin();
    }
};