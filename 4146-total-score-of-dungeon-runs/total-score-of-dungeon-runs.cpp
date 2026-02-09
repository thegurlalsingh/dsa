class Solution {
    long long helper(vector<int>& damage, vector<int>& requirement, vector<int>& prefix, int h, int start){
        long long count = 0;
        long long s = requirement[start] + prefix[start] - h;
        if(s <= 0){
            count++;
        }
        auto it = lower_bound(prefix.begin(), prefix.begin() + start, s);
        int idx = it - prefix.begin();
        count += (start - idx);
        return count;
    }
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        vector<long long> score(n);
        vector<int> prefix(n);
        prefix[0] = damage[0];
        for(int i = 1; i < n; i++){
            prefix[i] = prefix[i - 1] + damage[i];
        }
        for(int i = 0; i < n; i++){
            int temp = hp;
            score[i] = helper(damage, requirement, prefix, temp, i);
        }
        return accumulate(score.begin(), score.end(), 0LL);
    }
};