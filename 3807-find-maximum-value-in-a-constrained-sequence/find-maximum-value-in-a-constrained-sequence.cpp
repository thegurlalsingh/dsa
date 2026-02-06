class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {
        vector<long long> a(n, 1e18);
        map<int, int> mp;

        for (auto &r : restrictions) {
            if (mp.count(r[0]))
                mp[r[0]] = min(mp[r[0]], r[1]);
            else
                mp[r[0]] = r[1];
        }

        a[0] = 0;

        for (auto &it : mp) {
            a[it.first] = min(a[it.first], (long long)it.second);
        }

        for (int i = 1; i < n; i++) {
            a[i] = min(a[i], a[i - 1] + diff[i - 1]);
        }

        for (int i = n - 2; i >= 0; i--) {
            a[i] = min(a[i], a[i + 1] + diff[i]);
        }

        return *max_element(a.begin(), a.end());
    }
};
