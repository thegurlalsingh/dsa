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
    void solve(vector<TreeNode*>& nodes, TreeNode* root, int s){
        if(!root){
            return ;
        }
        if(root->val == s){
            nodes.push_back(root);
        }
        solve(nodes, root->left, s);
        solve(nodes, root->right, s);
    }
    bool isSame(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2){
            return true;
        }
        if(!root1 || !root2){
            return false;
        }
        if(root1->val != root2->val){
            return false;
        }
        return isSame(root1->right, root2->right) && isSame(root1->left, root2->left);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        vector<TreeNode*> nodes;
        solve(nodes, root, subRoot->val);
        for(int i = 0; i < nodes.size(); i++){
            bool temp = isSame(nodes[i], subRoot);
            if(temp){
                return true;
            }
        }
        return false;
    }
};