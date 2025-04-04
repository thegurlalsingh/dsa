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
    int maxDepth = -1;
    vector<TreeNode*> deepestNodes;

    void findDeepestNodes(TreeNode* root, int depth) {
        if (!root) return;
        
        if (!root->left && !root->right) { 
            if (depth > maxDepth) { 
                maxDepth = depth;
                deepestNodes.clear();
            }
            if (depth == maxDepth) {
                deepestNodes.push_back(root);
            }
        }
        
        findDeepestNodes(root->left, depth + 1);
        findDeepestNodes(root->right, depth + 1);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (!left) return right;
        if (!right) return left;
        return root;
    }

public:
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        findDeepestNodes(root, 0);

        if (deepestNodes.size() == 1) { 
            return deepestNodes[0];
        }

        TreeNode* lca = deepestNodes[0];
        for (int i = 1; i < deepestNodes.size(); i++) {
            lca = lowestCommonAncestor(root, lca, deepestNodes[i]);
        }

        return lca;
    }
};
