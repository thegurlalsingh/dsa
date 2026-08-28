/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool solve(TreeNode* root, long long mx, long long mn){
        if(!root){
            return true;
        }
        if(mn >= root->val || mx <= root->val){
            return false;
        }
        return solve(root->left, root->val, mn) && solve(root->right, mx, root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(!root->left && !root->right){
            return true;
        }
        return solve(root, LLONG_MAX, LLONG_MIN);
    }
};