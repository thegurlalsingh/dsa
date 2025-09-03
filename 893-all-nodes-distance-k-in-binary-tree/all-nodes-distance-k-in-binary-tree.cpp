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
public:
    unordered_map<TreeNode*, TreeNode*> parent;

    void buildParent(TreeNode* root, TreeNode* par) {
        if (!root) return;
        parent[root] = par;
        buildParent(root->left, root);
        buildParent(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        buildParent(root, nullptr);

        unordered_set<TreeNode*> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited.insert(target);

        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            if (dist == k) break;
            dist++;
            for (int i = 0; i < sz; i++) {
                TreeNode* node = q.front(); q.pop();
                vector<TreeNode*> nbrs = {node->left, node->right, parent[node]};
                for (TreeNode* nb : nbrs) {
                    if (nb && !visited.count(nb)) {
                        visited.insert(nb);
                        q.push(nb);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};
