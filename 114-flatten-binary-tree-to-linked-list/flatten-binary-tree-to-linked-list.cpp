class Solution {
private:
    TreeNode* solve(TreeNode* root, TreeNode*& temp) {
        if (!root) return temp;

        temp->right = new TreeNode(root->val);
        temp = temp->right;  

        temp = solve(root->left, temp);
        temp = solve(root->right, temp);

        return temp;
    }
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        TreeNode* dummy = new TreeNode(-1);
        TreeNode* temp = dummy;

        solve(root, temp);

        root->val   = dummy->right->val;
        root->left  = nullptr;
        root->right = dummy->right->right;

        delete dummy;  // free dummy node
    }
};
