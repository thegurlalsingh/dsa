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
class Solution { // preorder thing wont work here because preorder and prev in args of function will contain parent node only but if we want minimum diff between any two nodes then it can be in adjacent sorted values and for that we should do inorder because inorder of bst is always sorted values and put prev in global
    int ans = INT_MAX;
    int prev = -1;
    void solve(TreeNode*& temp){
        if(temp == nullptr){
            return ;
        }
        solve(temp->left);

        if(prev != -1){
            ans = min(ans, abs(temp->val - prev));
        }

        prev = temp->val;
        
        solve(temp->right);
    }
public:
    int minDiffInBST(TreeNode* root) {
        TreeNode* temp = root;
        solve(temp);
        return ans;
    }
};