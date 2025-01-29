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
private:
    int calc(TreeNode* temp, int targetSum, long long sum) {
        if (!temp) return 0; 

        sum += temp->val; 
        int ways = (sum == targetSum) ? 1 : 0; 

        ways += calc(temp->left, targetSum, sum);
        ways += calc(temp->right, targetSum, sum);

        return ways;
    }

public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0; 

        return calc(root, targetSum, 0) + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }
};
