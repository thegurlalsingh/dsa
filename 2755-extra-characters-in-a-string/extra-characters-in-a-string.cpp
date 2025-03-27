class TrieNode {
public:
    TrieNode* children[26];
    bool isEndOfWord;
    TrieNode() {
        isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx])
                node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEndOfWord = true;
    }
};

class Solution {
    Trie trie;
    int n;
    vector<int> memo;

    int backtrack(string& s, int start) {
        if (start == n)
            return 0;
        if (memo[start] != -1)
            return memo[start];
        int extraChars = 1 + backtrack(s, start + 1);
        TrieNode* node = trie.root;
        for (int i = start; i < n; i++) {
            int idx = s[i] - 'a';
            if (!node->children[idx])
                break;
            node = node->children[idx];
            if (node->isEndOfWord) {
                extraChars = min(extraChars, backtrack(s, i + 1));
            }
        }
        return memo[start] = extraChars;
    }

public:
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.size();
        memo.resize(n, -1);
        for (string word : dictionary) {
            trie.insert(word);
        }
        return backtrack(s, 0);
    }
};
