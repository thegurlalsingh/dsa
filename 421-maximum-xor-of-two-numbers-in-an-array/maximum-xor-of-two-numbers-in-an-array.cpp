class Trie {
    struct Node {
        Node* links[2];
        Node() {
            links[0] = links[1] = nullptr;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num) {
        Node* node = root;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;

            if (!node->links[bit]) {
                node->links[bit] = new Node();
            }

            node = node->links[bit];
        }
    }

    int getMaxXor(int num) {
        Node* node = root;
        int ans = 0;

        for (int i = 31; i >= 0; i--) {
            int bit = (num >> i) & 1;
            int opp = 1 - bit;

            if (node->links[opp]) {
                ans |= (1 << i);
                node = node->links[opp];
            } else {
                node = node->links[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        
        int ans = 0;

        for(int i = 0; i < nums.size(); i++){
            t.insert(nums[i]);
        }

        for(int i = 0; i < nums.size(); i++){
            ans = max(ans, t.getMaxXor(nums[i]));
        }

        return ans;
    }
};