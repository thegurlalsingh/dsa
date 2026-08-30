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
    unordered_map<long long, int> mp;
    int paths = 0;
    void solve(TreeNode* root, int targetSum, long long sum){
        if(!root){
            return ;
        }
        sum += root->val;
        if(mp.count(sum - targetSum)){
            paths += mp[sum - targetSum];
        }
        mp[sum]++;
        solve(root->left, targetSum, sum);
        solve(root->right, targetSum, sum);
        mp[sum]--;
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        mp[0] = 1;
        int path = 0;
        solve(root, targetSum, 0 * 1LL);
        return paths;
    }
};