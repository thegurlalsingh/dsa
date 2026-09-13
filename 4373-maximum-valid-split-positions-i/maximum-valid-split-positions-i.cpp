class Solution {
    vector<int> p(vector<int>& n){
        vector<int> r(n.size(), 0);
        r[0] = n[0];
        for(int i = 1; i < n.size(); i++){
            r[i] = gcd(n[i], r[i - 1]);
        }
        return r;
    }

    vector<int> s(vector<int>& n){
        vector<int> r(n.size(), 0);
        r[n.size() - 1] = n[n.size() - 1];
        for(int i = n.size() - 2; i >= 0; i--){
            r[i] = gcd(n[i], r[i + 1]);
        }
        return r;
    }
public:
    int maxValidSplits(vector<int>& nums) {
        int splits = 0;
        // excluding one element

        for(int i = 0; i < nums.size(); i++){
            int t = 0;

            vector<int> n;
            for(int j = 0; j < nums.size(); j++){
                if(j != i){
                    n.push_back(nums[j]);
                }
            }

            vector<int> prefixgcd = p(n);
            vector<int> suffixgcd = s(n);

            for(int j = 0; j < prefixgcd.size() - 1; j++){
                if(prefixgcd[j] == suffixgcd[j + 1]){
                    t++;
                }
            }

            splits = max(t, splits);
        }


        vector<int> prefixgcd = p(nums);
        vector<int> suffixgcd = s(nums);

        int t = 0;

        for(int i = 0; i < prefixgcd.size() - 1; i++){
            if(prefixgcd[i] == suffixgcd[i + 1]){
                t++;
            }
        }

        splits = max(t, splits);

        return splits;
    }
};