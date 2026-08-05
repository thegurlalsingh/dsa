struct Node {
    int cnt;

    Node() { cnt = 0; }
};

class SegmentTree {
private:
    vector<Node> tree;
    int n;

public:
    SegmentTree(int sz) {
        n = sz;
        tree.resize(4 * n + 5);
    }

    Node merge(Node left, Node right) {
        Node res;
        res.cnt = left.cnt + right.cnt;
        return res;
    }

    void update(int node, int l, int r, int idx) {
        if (l == r) {
            tree[node].cnt++;
            return;
        }

        int mid = (l + r) / 2;
        if (idx <= mid) {
            update(node * 2, l, mid, idx);
        } else {
            update(node * 2 + 1, mid + 1, r, idx);
        }

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int idx) { 
        update(1, 1, n, idx); 
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (qr < l || ql > r) {
            return Node();
        }
        if (ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;
        return merge(query(node * 2, l, mid, ql, qr), query(node * 2 + 1, mid + 1, r, ql, qr));
    }

    int query(int l, int r) {
        if (l > r) {
            return 0;
        }
        return query(1, 1, n, l, r).cnt;
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        vector<long long> prefix(nums.size() + 1);
        prefix[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2 == 0){
                prefix[i + 1] = prefix[i] + b;
            }
            else{
                prefix[i + 1] = prefix[i] - a;
            }
        }

        vector<long long> values = prefix;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        SegmentTree st(values.size());
        long long ans = 0;
        for(int i = 0; i < prefix.size(); i++){
            int rank = lower_bound(values.begin(), values.end(), prefix[i]) - values.begin() + 1;
            ans += st.query(rank, values.size());
            st.update(rank);
        }
        return ans;
    }
};