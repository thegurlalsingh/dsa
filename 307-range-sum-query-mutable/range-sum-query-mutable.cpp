class SegmentTree {
public:
    struct Node {
        long long sum;

        Node() { 
            sum = 0; 
        }

        Node(long long val) { 
            sum = val; 
        }
    };

    vector<Node> seg;
    int n;

    SegmentTree(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    Node merge(Node left, Node right) {
        Node res;
        res.sum = left.sum + right.sum;
        return res;
    }

    void build(int idx, int low, int high, vector<int>& arr) {

        if (low == high) {
            seg[idx] = Node(arr[low]);
            return;
        }

        int mid = (low + high) / 2;

        build(2 * idx + 1, low, mid, arr);
        build(2 * idx + 2, mid + 1, high, arr);

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    Node query(int idx, int low, int high, int l, int r) {
        if (high < l || low > r) {
            return Node(0);
        }

        if (low >= l && high <= r) {
            return seg[idx];
        }

        int mid = (low + high) / 2;

        Node left = query(2 * idx + 1, low, mid, l, r);

        Node right = query(2 * idx + 2, mid + 1, high, l, r);

        return merge(left, right);
    }

    void update(int idx, int low, int high, int pos, int val) {

        if (low == high) {
            seg[idx] = Node(val);
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid) {
            update(2 * idx + 1, low, mid, pos, val);
        } else {
            update(2 * idx + 2, mid + 1, high, pos, val);
        }

        seg[idx] = merge(seg[2 * idx + 1], seg[2 * idx + 2]);
    }
};

class NumArray {
public:
    vector<int> nums;
    SegmentTree st;

    NumArray(vector<int>& nums) : nums(nums), st(this->nums) { }

    void update(int index, int val) {
        st.update(0, 0, nums.size() - 1, index, val);     
    }

    int sumRange(int left, int right) {
        return st.query(0, 0, nums.size() - 1, left, right).sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */