class Solution {
private:
    void inorderTraversal(TreeNode* root, vector<int>& arr) {
        if (!root) return;
        inorderTraversal(root->left, arr);
        arr.push_back(root->val);
        inorderTraversal(root->right, arr);
    }

public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        vector<int> arr;
        inorderTraversal(root, arr);

        int sum = 0;
        int i = 0;
        while(i < arr.size()){
            if(arr[i] >= low && arr[i] <= high){
                sum += arr[i];
            }
            i++;
        }

        return sum;
    }
};
