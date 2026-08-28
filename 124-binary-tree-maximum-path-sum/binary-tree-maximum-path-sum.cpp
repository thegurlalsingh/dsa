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
    int ans = INT_MIN;
    int solve(TreeNode* root){
        if(!root){
            return 0;
        }
        int leftSum = max(0, solve(root->left));
        int rightSum = max(0, solve(root->right));

        ans = max(ans, leftSum + rightSum + root->val);

        return root->val + max(leftSum, rightSum);
    }

public:
    int maxPathSum(TreeNode* root) {
        if(!root->left && !root->right){
            return root->val;
        }
        solve(root);
        return ans;
    }
};