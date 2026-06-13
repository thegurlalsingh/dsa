class SegmentTree {
public:
    struct Node {
        int sum = 0;
    };

    vector<Node> seg;
    int n;

    SegmentTree(int n) {
        this->n = n;
        seg.resize(4 * n);
    }

    Node merge(Node left, Node right) {
        Node res;
        res.sum = left.sum + right.sum;
        return res;
    }

    void update(int idx, int low, int high, int pos) {

        if (low == high) {
            seg[idx].sum++;
            return;
        }

        int mid = (low + high) / 2;

        if (pos <= mid)
            update(2 * idx + 1, low, mid, pos);
        else
            update(2 * idx + 2, mid + 1, high, pos);

        seg[idx] = merge(
            seg[2 * idx + 1],
            seg[2 * idx + 2]
        );
    }

    Node query(int idx, int low, int high, int l, int r) {

        if (high < l || low > r)
            return Node();

        if (low >= l && high <= r)
            return seg[idx];

        int mid = (low + high) / 2;

        return merge(
            query(2 * idx + 1, low, mid, l, r),
            query(2 * idx + 2, mid + 1, high, l, r)
        );
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();

        vector<long long> prefix(n + 1, 0);

        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }

        vector<long long> all;

        for(auto x : prefix){
            all.push_back(x);
            all.push_back(x - lower);
            all.push_back(x - upper);
        }

        sort(all.begin(), all.end());

        all.erase(unique(all.begin(), all.end()), all.end());

        auto getRank = [&](long long x){
            return lower_bound(all.begin(), all.end(), x) - all.begin();
        };

        SegmentTree st(all.size());

        long long ans = 0;
        for(auto curr : prefix){
            long long leftVal = curr - upper;
            long long rightVal = curr - lower;
            int leftRank = getRank(leftVal);
            int rightRank = getRank(rightVal);
            ans += st.query(0, 0, all.size()-1, leftRank, rightRank).sum;
            st.update(0, 0, all.size()-1, getRank(curr));
        }

        return ans;
    }
};