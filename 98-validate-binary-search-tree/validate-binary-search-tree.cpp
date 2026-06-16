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
    bool solve(long long left, long long right, TreeNode* root){
        if(!root){
            return true;
        }
        if(root->val <= left || root->val >= right){
            return false;
        }
        return solve(left, root->val, root->left) && solve(root->val, right, root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr){
            return true;
        }
        return solve(-1e18, 1e18, root);
    }
};