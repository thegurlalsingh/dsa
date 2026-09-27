class Trie {
public:
    struct Node {
        Node* child[2];
        bool isEnd;
        Node() {
            isEnd = false;
            for (int i = 0; i < 2; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;

    Trie() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;
        for (int ch : word) {
            int idx = ch - '0';
            if (curr->child[idx] == nullptr) {
                curr->child[idx] = new Node();
            }
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }

    string search(string word) {
        Node* curr = root;
        string ans = "";
        for (int i = 0; i < word.size(); i++) {
            if (word[i] == '1') {
                if (curr->child['0' - '0'] != nullptr) {
                    curr = curr->child['0' - '0'];
                    ans.push_back('0');
                } else if (curr->child['1' - '0'] != nullptr) {
                    curr = curr->child['1' - '0'];
                    ans.push_back('1');
                }
            }

            else {
                if (curr->child['1' - '0'] != nullptr) {
                    curr = curr->child['1' - '0'];
                    ans.push_back('1');
                } else if (curr->child['0' - '0'] != nullptr) {
                    curr = curr->child['0' - '0'];
                    ans.push_back('0');
                }
            }
        }
        if (curr->isEnd) {
            return ans;
        }
        return "";
    }
};

class Solution {
    string toBinary(int num) {
        string binary = "";

        while (num > 0) {
            binary += char((num % 2) + '0');
            num /= 2;
        }

        while (binary.size() < 32) {
            binary += '0';
        }

        reverse(binary.begin(), binary.end());

        return binary;
    }

    int toNumber(string binary) {
        int num = 0;

        for (char ch : binary) {
            num = num * 2 + (ch - '0');
        }

        return num;
    }

public:
    int findMaximumXOR(vector<int>& nums) {
        Trie t;
        for (int i = 0; i < nums.size(); i++) {
            t.insert(toBinary(nums[i]));
        }
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            ans = max(ans, nums[i] ^ toNumber(t.search(toBinary(nums[i]))));
        }
        return ans;
    }
};