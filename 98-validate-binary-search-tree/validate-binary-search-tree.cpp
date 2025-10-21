class Solution {
    bool solve(TreeNode* temp, long long minVal, long long maxVal) {
        if (!temp) return true;
        if (temp->val <= minVal || temp->val >= maxVal) return false;

        // Check left subtree with updated upper bound
        bool left = solve(temp->left, minVal, temp->val);

        // Check right subtree with updated lower bound
        bool right = solve(temp->right, temp->val, maxVal);

        return left && right;
    }

public:
    bool isValidBST(TreeNode* root) {
        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
