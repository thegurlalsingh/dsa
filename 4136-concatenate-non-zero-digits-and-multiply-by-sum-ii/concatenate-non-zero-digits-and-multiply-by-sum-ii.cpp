class Solution {
public:
    static const int MOD = 1e9 + 7;

    struct Node {
        long long x = 0;
        long long sum = 0;
        long long cnt = 0;
    };

    vector<Node> seg;
    vector<long long> pow10;
    string s;
    int n;

    Node merge(const Node &L, const Node &R) {
        Node res;
        res.cnt = L.cnt + R.cnt;
        res.sum = L.sum + R.sum;
        // L.x shifted by 10^(R.cnt) + R.x
        res.x = (L.x * pow10[R.cnt] + R.x) % MOD;
        return res;
    }

    Node make_node(char c) {
        Node t;
        if (c != '0') {
            int d = c - '0';
            t.cnt = 1;
            t.sum = d;
            t.x = d;
        }
        return t;
    }

    void build(int idx, int l, int r) {
        if (l == r) {
            seg[idx] = make_node(s[l]);
            return;
        }
        int mid = (l + r) >> 1;
        build(idx<<1, l, mid);
        build(idx<<1|1, mid+1, r);
        seg[idx] = merge(seg[idx<<1], seg[idx<<1|1]);
    }

    Node query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return Node();

        if (ql <= l && r <= qr) return seg[idx];
        int mid = (l + r) >> 1;
        Node L = query(idx<<1, l, mid, ql, qr);
        Node R = query(idx<<1|1, mid+1, r, ql, qr);
        return merge(L, R);
    }

    vector<int> sumAndMultiply(string s_, vector<vector<int>>& queries) {
        s = s_;
        n = s.size();

        seg.assign(4*n, Node());
        pow10.assign(n+1, 1);

        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i-1] * 10) % MOD;

        build(1, 0, n-1);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto &q : queries) {
            int l = q[0], r = q[1];
            Node res = query(1, 0, n-1, l, r);
            long long out = (res.x * res.sum) % MOD;
            ans.push_back(out);
        }
        return ans;
    }
};