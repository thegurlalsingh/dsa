class Solution {
    int n, m;
private:
    bool ok(vector<vector<int>>& a, int f) {
        for (int i = 0; i < n; i++) {
            bool can = false;
            for (int j = 0; j < m; j++) {
                int x = a[i][j];
                if ((x & f) == 0) can = true;
            }
            if (!can) return false;
        }
        return true;
    }
public:
    int minimumOR(vector<vector<int>>& a) {
        n = a.size();
        m = a[0].size();
        int ans = 0;
        int f = 0;

        for (int i = 30; i >= 0; i--) {
            int ff = f | (1 << i);

            if (ok(a, ff)) {
                f |= (1 << i);
            } else {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};