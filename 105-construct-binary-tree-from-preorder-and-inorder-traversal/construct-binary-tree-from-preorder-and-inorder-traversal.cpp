class Solution {
    void solve(TreeNode* root, vector<int>& preorder, vector<int>& inorder, unordered_map<int, int>& mp, int& preIdx, int s, int e) {
        int rootIdx = mp[root->val];
        if (s <= rootIdx - 1) {
            root->left = new TreeNode(preorder[preIdx++]);
            solve(root->left, preorder, inorder, mp, preIdx, s, rootIdx - 1);
        }

        if (rootIdx + 1 <= e) {
            root->right = new TreeNode(preorder[preIdx++]);
            solve(root->right, preorder, inorder, mp, preIdx, rootIdx + 1, e);
        }
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int preIdx = 1;
        solve(root, preorder, inorder, mp, preIdx, 0, inorder.size() - 1);

        return root;
    }
};