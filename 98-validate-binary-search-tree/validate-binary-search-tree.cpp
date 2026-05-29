class Solution {
    bool solve(TreeNode* root, long long low, long long high) {
        if(root == nullptr){
            return true;
        }
        if(root->val <= low || root->val >= high){
            return false;
        }
        return solve(root->left, low, root->val) && solve(root->right, root->val, high);
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};