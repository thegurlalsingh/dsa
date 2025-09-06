class Solution {
public:
    int find(vector<int>& inorder, int left, int right, int target){
        for(int i=left; i<=right; i++){
            if(inorder[i]==target){
                return i;
            }
        }
        return -1;
    }

    TreeNode* helper(vector<int>& preorder, vector<int>& inorder, int& preIdx, int left, int right){
        if(left > right){
            return NULL;
        }

        TreeNode* root = new TreeNode(preorder[preIdx]);

        int inIdx = find(inorder, left, right, preorder[preIdx]);
        preIdx++;

        root->left = helper(preorder, inorder, preIdx, left, inIdx-1);
        root->right = helper(preorder, inorder, preIdx, inIdx+1, right);
        
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        int left = 0;
        int right = preorder.size()-1;
        return helper(preorder, inorder, preIdx, left, right);
    }
};