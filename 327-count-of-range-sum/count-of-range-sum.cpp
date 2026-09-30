class MergeSortTree {

private:
    vector<vector<long long>> tree;
    int n;

    void build(int node, int l, int r, vector<long long>& arr) {

        if(l == r) {
            tree[node].push_back(arr[l]);
            return;
        }

        int mid = l + (r - l) / 2;

        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);

        merge(
            tree[2 * node].begin(),
            tree[2 * node].end(),
            tree[2 * node + 1].begin(),
            tree[2 * node + 1].end(),
            back_inserter(tree[node])
        );
    }

    long long query1(
        long long node,
        int l,
        int r,
        int ql,
        int qr,
        long long x
    ) {

        if(r < ql || l > qr)
            return 0;

        if(ql <= l && r <= qr) {

            auto it = upper_bound(
                tree[node].begin(),
                tree[node].end(),
                x
            );

            return it - tree[node].begin();
        }

        int mid = l + (r - l) / 2;

        return query1(2 * node, l, mid, ql, qr, x)
             + query1(2 * node + 1, mid + 1, r, ql, qr, x);
    }

    long long query2(
        long long node,
        int l,
        int r,
        int ql,
        int qr,
        long long x
    ) {

        if(r < ql || l > qr)
            return 0;

        if(ql <= l && r <= qr) {

            int count = lower_bound(tree[node].begin(), tree[node].end(), x) - tree[node].begin();

            return count;
        }

        int mid = l + (r - l) / 2;

        return query2(2 * node, l, mid, ql, qr, x)
             + query2(2 * node + 1, mid + 1, r, ql, qr, x);
    }

public:

    MergeSortTree(vector<long long>& arr) {

        n = arr.size();

        tree.resize(4 * n);

        build(1, 0, n - 1, arr);
    }

    long long countLessThan(long long x, int l, int r) {

        return query2(1, 0, n - 1, l, r, x);
    }

    long long countLessEqual(long long x, int l, int r) {

        return query1(1, 0, n - 1, l, r, x);
    }
};

class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        vector<long long> prefix(nums.size(), 0LL);
        prefix[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            prefix[i] = nums[i] + prefix[i - 1];
        }
        prefix.insert(prefix.begin(), 0);
        MergeSortTree mt(prefix);

        int ans = 0;
        for(int i = 1; i < prefix.size(); i++){
            long long left = prefix[i] - upper;
            long long right = prefix[i] - lower;

            ans += mt.countLessEqual(right, 0, i - 1);
            ans -= mt.countLessThan(left, 0, i - 1);
        }
        return ans;
    }
};