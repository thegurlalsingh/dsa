class Trie {

    struct Node {
        Node* links[26];

        bool isEnd;

        Node() {
            for (int i = 0; i < 26; i++)
                links[i] = NULL;

            isEnd = false;
        }
    };

    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word) {

        Node* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->links[idx] == NULL)
                node->links[idx] = new Node();

            node = node->links[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {

        Node* node = root;

        for (char ch : word) {

            int idx = ch - 'a';

            if (node->links[idx] == NULL)
                return false;

            node = node->links[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {

        Node* node = root;

        for (char ch : prefix) {

            int idx = ch - 'a';

            if (node->links[idx] == NULL)
                return false;

            node = node->links[idx];
        }

        return true;
    }
};

class Solution {
public:
    string longestWord(vector<string>& words) {
        Trie trie;

        for (int i = 0; i < words.size(); i++) {
            trie.insert(words[i]);
        }
        
        string longest = "";

        for (int i = 0; i < words.size(); i++) {

            string word = words[i];

            vector<string> pre(word.size());

            pre[0] = string(1, word[0]);

            for (int j = 1; j < word.size(); j++) {
                pre[j] = pre[j - 1] + word[j];
            }

            bool found = true;

            for (int j = 0; j < pre.size(); j++) {
                if (!trie.search(pre[j])) {
                    found = false;
                    break;
                }
            }

            if (found) {

                if (word.size() > longest.size()) {
                    longest = word;
                } else if (word.size() == longest.size() && word < longest) {
                    longest = word;
                }
            }
        }
        return longest;
    }
};