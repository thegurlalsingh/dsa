class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        while(root && (root->val < low || root->val > high)) root = (root->val < low) ? root->right : root->left;
        if(!root) return root;
        TreeNode* curr = root;
        while(curr->left){
            if(curr->left->val < low) curr->left = curr->left->right;
            else curr = curr->left;
        }
        curr = root;
        while(curr->right){
            if(curr->right->val > high) curr->right = curr->right->left;
            else curr = curr->right;
        }
        return root;
    }
};