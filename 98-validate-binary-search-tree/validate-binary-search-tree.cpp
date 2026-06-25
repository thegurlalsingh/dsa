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
    bool solve(long long mini, long long maxi, TreeNode* root){
        if(root == nullptr){
            return true;
        }
        if(root->val <= mini || root->val >= maxi){
            return false;
        }
        return solve(mini, root->val, root->left) && solve(root->val, maxi, root->right);
    }
public:
    bool isValidBST(TreeNode* root) {
        return solve(-1e12 - 3, 1e12 + 3, root);
    }
};