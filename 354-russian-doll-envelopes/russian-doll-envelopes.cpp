class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b){
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }

            return a[0] < b[0];
        }); // width increasing, height decreasing

        // for loop version of lis
        int n=envelopes.size();
        auto it_ = envelopes.begin();
        vector<int> tails;
        for(int i = 0; i < n; i++){
            int k = envelopes[i][1];
            if(tails.empty() || tails.back() < k){
                tails.push_back(k);
            }
            else{
                auto it = lower_bound(tails.begin(), tails.end(), k); // finding first element >= k;
                *it = k; // then replacing that element with k in tails array -> this will not break lis -> I am keeping the same LIS length but making its ending value as small as possible.
            }
        }
        return tails.size();
    }
};