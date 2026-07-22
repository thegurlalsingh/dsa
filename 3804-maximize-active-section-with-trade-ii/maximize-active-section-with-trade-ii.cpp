struct Tree {
    int n;
    vector<vector<int>> lidx, ridx;
    vector<int> segtree;
    string t;
    Tree(string &s) {
        n = s.size();
        t = s;
        segtree.resize(4*n);
        lidx.assign(2, vector<int>(n));
        ridx.resize(2, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int x = s[i] - '0';
            lidx[x][i] = (i == 0 || (s[i] != s[i - 1]) ? i : lidx[x][i - 1]);
        }
        for (int i = n - 1; i >= 0; i--) {
            int x = s[i] - '0';
            ridx[x][i] = (i == n - 1 || (s[i] != s[i + 1]) ? i : ridx[x][i + 1]);
        }
        build(1, 0, n - 1);
    }
    int merge(int lseg, int rseg, int s, int m, int e) {
        if (s == e) return 0;
        int res = max(lseg, rseg);
        if (t[m] == t[m + 1]) {
            if (t[m] == '1') {
                if (lidx[1][m] - 1 >= s && ridx[1][m] + 1 <= e) {
                    int L = max(s, lidx[0][lidx[1][m] - 1]);
                    int R = min(e, ridx[0][ridx[1][m] + 1]);
                    res = max(res, R - L + 1 - (ridx[1][m] - lidx[1][m] + 1));
                }
            } else {
                {
                    int idx1 = lidx[0][m] - 1;
                    if (idx1 >= s) {
                        int idx0 = lidx[1][idx1] - 1;
                        if (idx0 >= s) {
                            int L = max(s, lidx[0][idx0]);
                            int R = min(e, ridx[0][m]);
                            res = max(res, R - L + 1 - (ridx[1][idx1] - lidx[1][idx1] + 1));
                        }
                    }
                }
                
                {
                    int idx1 = ridx[0][m] + 1;
                    if (idx1 <= e) {
                        int idx0 = ridx[1][idx1] + 1;
                        if (idx0 <= e) {
                            int L = max(s, lidx[0][m]);
                            int R = min(e, ridx[0][idx0]);
                            res = max(res, R - L + 1 - (ridx[1][idx1] - lidx[1][idx1] + 1));
                        }
                    }
                }
            }
        } else {  
            if (t[m] == '1') {
                if (lidx[1][m] - 1 >= s) {
                    int L = max(s, lidx[0][lidx[1][m] - 1]);
                    int R = min(e, ridx[0][m + 1]);
                    res = max(res, R - L + 1 - (ridx[1][m] - lidx[1][m] + 1));
                }
            } 
            else {
                if (ridx[1][m + 1] + 1 <= e) {
                    int L = max(s, lidx[0][m]);
                    int R = min(e, ridx[0][ridx[1][m + 1] + 1]);
                    res = max(res, R - L + 1 - (ridx[1][m + 1] - lidx[1][m + 1] + 1));
                }
            }
        }
        return res;
    }
    void build(int idx, int s, int e) {
        if (s == e) return;
        int m = (s + e)/2;
        build(2*idx, s, m);
        build(2*idx + 1, m + 1, e);
        segtree[idx] = merge(segtree[2*idx], segtree[2*idx + 1], s, m, e);
    }
    int query(int idx, int s, int e, int l, int r) {
        if (s > r || l > e || s > e || l > r) return -1;
        if (l <= s && e <= r) return segtree[idx];
        int m = (s + e)/2;
        int lans = query(2*idx, s, m, l, r);
        if (lans == -1) return query(2*idx + 1, m + 1, e, l, r);
        int rans = query(2*idx + 1, m + 1, e, l, r);
        if (rans == -1) return lans;
        return merge(lans, rans, max(s, l), m, min(e, r));
    }
};
class Solution {
public:
    vector<int> maxActiveSectionsAfterTrade(string s, vector<vector<int>>& queries) {
        Tree tree(s);
        int m = queries.size();
        int n = s.size();
        vector<int> ans(m);
        int cnt = 0;
        for (int i = 0; i < n; i++) if (s[i] == '1') cnt++;
        for (int i = 0; i < m; i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = cnt + tree.query(1, 0, n - 1, l, r);
        }
        return ans;
    }
};

