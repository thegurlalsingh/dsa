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
class FindElements {
    TreeNode* root;
    unordered_set<int> values; 

    void restore(TreeNode* node, int val) {
        if (!node) {
            return;
        }
        node->val = val;
        values.insert(val);
        restore(node->left, (2 * val) + 1);
        restore(node->right, (2 * val) + 2);
    }

public:
    FindElements(TreeNode* root) {
        this->root = root;
        if (root) {
            restore(root, 0); 
        }
    }
    
    bool find(int target) {
        return values.find(target) != values.end(); 
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */