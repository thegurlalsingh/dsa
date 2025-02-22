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

        int idx1 = -1, idx2 = -1;
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == low) idx1 = i;
            if (arr[i] == high) idx2 = i;
        }

        if (idx1 == -1 || idx2 == -1) 
        {
            return 0;
        }
        if (idx1 > idx2) {
            swap(idx1, idx2);
        }
        
        int sum = 0;
        for (int i = idx1; i <= idx2; i++) {
            sum += arr[i];
        }

        return sum;
    }
};
