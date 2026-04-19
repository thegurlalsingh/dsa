class SegmentTree {
public:
    struct Node {
        int mx;  

        Node(int val = INT_MIN) {
            mx = val;
        }
    };

    int n;
    vector<Node> tree;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        tree.resize(4 * n);
        build(1, 0, n - 1, arr);
    }

    Node merge(Node a, Node b) {
        return Node(max(a.mx, b.mx));
    }

    void build(int node, int l, int r, vector<int>& arr) {
        if (l == r) {
            tree[node] = Node(arr[l]);
            return;
        }

        int mid = (l + r) / 2;
        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = Node(val);
            return;
        }

        int mid = (l + r) / 2;

        if (idx <= mid)
            update(2 * node, l, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, r, idx, val);

        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Node query(int node, int l, int r, int ql, int qr) {
        if (r < ql || l > qr)
            return Node();  

        if (ql <= l && r <= qr)
            return tree[node];

        int mid = (l + r) / 2;

        Node left = query(2 * node, l, mid, ql, qr);
        Node right = query(2 * node + 1, mid + 1, r, ql, qr);

        return merge(left, right);
    }
    
    int queryCustom(int node, int l, int r, int x, int ans) {
        if (tree[node].mx < x || (tree[node].mx == INT_MIN)){
            return -1;  
        }

        if (l >= r) {
            return l;  
        }

        int mid = (l + r) / 2;

        if (tree[2*node].mx >= x){
            int temp = max(tree[2*node].mx, ans);
            return queryCustom(2*node, l, mid, x, temp);
        }
        else{
            return queryCustom(2*node+1, mid+1, r, x, ans);
        }
    }
};

class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        SegmentTree st(baskets);
        int n = fruits.size();
        int unplaced = 0;
        for(int i = 0; i < n; i++){
            int q = st.queryCustom(1, 0, n - 1, fruits[i], INT_MAX);
            if(q == -1){
                unplaced++;
            }
            else{
                st.update(1, 0, n - 1, q, INT_MIN); //INT_MIN for used, returning -1 when you cant find any basket
            }
        }
        return unplaced;
    }
};