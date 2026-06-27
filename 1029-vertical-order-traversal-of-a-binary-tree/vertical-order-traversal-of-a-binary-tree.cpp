/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        unordered_map<TreeNode*, pair<int, int>> mp;
        mp[root] = {0, 0};
        queue<tuple<TreeNode*, int, int>> q;
        q.push({root, 0, 0});

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [node, row, col] = q.front();
                q.pop();

                if (node->left) {
                    q.push({node->left, row + 1, col - 1});
                    mp[node->left] = {row + 1, col - 1};
                }
                if (node->right) {
                    q.push({node->right, row + 1, col + 1});
                    mp[node->right] = {row + 1, col + 1};
                }
            }
        }
        vector<int> cols;
        unordered_map<int, vector<pair<int, int>>> a;

        for (auto &p : mp) {
            cols.push_back(p.second.second);
        }

        sort(cols.begin(), cols.end());
        cols.erase(unique(cols.begin(), cols.end()), cols.end());

        for (auto& p : mp) {
            int row = p.second.first;
            int col = p.second.second;

            a[col].push_back({row, p.first->val});
        }

        for (auto &p : a) {
            sort(p.second.begin(), p.second.end());
        }

        vector<vector<int>> ans;
        for (int col : cols) {
            vector<int> temp;

            for (auto& x : a[col]) {
                temp.push_back(x.second);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};