class Solution {
    void solve(TreeNode* n, TreeNode* root){
        if (!root) return;

        if (root->right) {
            n->left = new TreeNode(root->right->val);
            solve(n->left, root->right);
        }
        if (root->left) {
            n->right = new TreeNode(root->left->val);
            solve(n->right, root->left);
        }
    }

public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;
        TreeNode* n = new TreeNode(root->val);
        solve(n, root);
        return n;
    }
};
