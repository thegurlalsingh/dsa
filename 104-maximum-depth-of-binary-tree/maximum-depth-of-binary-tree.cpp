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
    void solve(int curr, TreeNode* root, int& d){
        if(root == nullptr){
            d = max(d, curr);
            return ;
        }
        
        solve(curr + 1, root->left, d);
        solve(curr + 1, root->right, d);
    }
public:
    int maxDepth(TreeNode* root) {
        int d = 0;
        solve(0, root, d);
        return d;
    }
};