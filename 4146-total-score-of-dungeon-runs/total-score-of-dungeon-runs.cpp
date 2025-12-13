class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        int n = damage.size();
        long long count = 0;

        vector<long long> prefix(n);
        prefix[0] = damage[0];
        for (int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + damage[i];

        for (int i = 0; i < n; i++) {
            long long s = prefix[i] + requirement[i] - hp;

            if (s <= 0)
                count++;   

            auto it = lower_bound(prefix.begin(), prefix.begin() + i, s);
            int idx = it - prefix.begin();

            count += (i - idx);
        }

        return count;
    }
};
