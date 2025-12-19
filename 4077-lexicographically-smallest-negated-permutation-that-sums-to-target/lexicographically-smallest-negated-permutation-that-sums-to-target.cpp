class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int &n, long long &target) {
        long long S = 1LL * n * (n + 1) / 2;

        if (abs(target) > S || (S - target) % 2 != 0)
            return {};

        long long need = (S - target) / 2;
        vector<bool> neg(n + 1, false);

        for (int i = n; i >= 1; i--) {
            if (i <= need) {
                neg[i] = true;
                need -= i;
            }
        }

        if (need != 0) return {};

        vector<int> ans;
        for (int i = 1; i <= n; i++) {
            if (neg[i]) ans.push_back(-i);
            else ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
