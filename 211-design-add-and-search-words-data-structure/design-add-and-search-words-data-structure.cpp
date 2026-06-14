class Trie {
    struct Node {
        Node* links[26];
        bool isEnd;
        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
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
            if (node->links[idx] == nullptr) {
                node->links[idx] = new Node();
            }
            node = node->links[idx];
        }
        node->isEnd = true;
    }

    bool dfs(string& word, int i, Node* node) {
        if (i == word.size()) {
            return node->isEnd;
        }
        if (word[i] != '.') {
            int idx = word[i] - 'a';
            if (node->links[idx] == NULL) {
                return false;
            }
            return dfs(word, i + 1, node->links[idx]);
        } else {
            for (char c = 'a'; c <= 'z'; c++) {
                int idx = c - 'a';
                if (node->links[idx] != NULL) {
                    // word[i] = c;
                    if (dfs(word, i + 1, node->links[idx])) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    bool search(string word) {
        Node* node = root;
        return dfs(word, 0, node);
    }
};

class WordDictionary {
public:
    Trie t;
    WordDictionary() {}

    void addWord(string word) { t.insert(word); }

    bool search(string word) { return t.search(word); }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */