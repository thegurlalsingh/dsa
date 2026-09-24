class MergeSortTree{
    public:
    vector<vector<int>> tree; int n;

    void build(int node, int l, int r, vector<int>& arr){
        if(l == r){
            tree[node].push_back(arr[l]);
            return ;
        }
        int mid = l + (r - l) / 2;
        build(2 * node, l, mid, arr);
        build(2 * node + 1, mid + 1, r, arr);

        merge(tree[2 * node].begin(), tree[2 * node].end(), tree[2 * node + 1].begin(), tree[2 * node + 1].end(), back_inserter(tree[node]));
    }

    int query(int node, int l, int r, int ql, int qr, int x){
        if(r < ql || l > qr){
            return 0;
        }
        if(ql <= l && r <= qr){
            auto it = lower_bound(tree[node].begin(), tree[node].end(), x);
            int pos = it - tree[node].begin();
            return pos;
        }
        int mid = l + (r - l) / 2;
        return query(2 * node, l, mid, ql, qr, x) + query(2 * node + 1, mid + 1, r, ql, qr, x);
    }
};

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        vector<int> n;
        MergeSortTree mg;
        mg.n = nums.size();
        mg.tree.resize(4 * nums.size());
        mg.build(1, 0, nums.size() - 1, nums);

        vector<int> ans(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++){
            ans[i] = mg.query(1, 0, nums.size() - 1, i + 1, nums.size() - 1, nums[i]);
        }

        return ans;
    }
};