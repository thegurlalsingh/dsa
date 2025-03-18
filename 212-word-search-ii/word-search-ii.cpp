class Trie {
public:
    struct trieNode {
        trieNode* children[26];  
        bool endOfWord;          
    };

    trieNode* getNode() {
        trieNode* newNode = new trieNode();
        newNode->endOfWord = false;
        for (int i = 0; i < 26; i++) {
            newNode->children[i] = NULL;
        }
        return newNode;
    }

    void freeTrie(trieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                freeTrie(root->children[i]);
            }
        }
        delete root;
    }

    void displayUtil(trieNode* root, string current) {
        if (root->endOfWord) {
            cout << current << endl;
        }
        for (int i = 0; i < 26; i++) {
            if (root->children[i]) {
                displayUtil(root->children[i], current + char(i + 'a'));
            }
        }
    }

    trieNode* root;

    Trie() {
        root = getNode();
    }

    ~Trie() {
        freeTrie(root);
    }

    int getIndex(char ch) {
        return ch - 'a';
    }

    void insert(string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.length(); i++) {
            int index = getIndex(word[i]);
            if (!crawler->children[index]) {
                crawler->children[index] = getNode();
            }
            crawler = crawler->children[index];
        }
        crawler->endOfWord = true;
    }

    bool search(string word) {
        trieNode* crawler = root;
        for (int i = 0; i < word.length(); i++) {
            int index = getIndex(word[i]);
            if (!crawler->children[index]) {
                return false;  
            }
            crawler = crawler->children[index];
        }
        return crawler->endOfWord;  
    }

    bool startsWith(string prefix) {
        trieNode* crawler = root;
        for (int i = 0; i < prefix.length(); i++) {
            int index = getIndex(prefix[i]);
            if (!crawler->children[index]) {
                return false;
            }
            crawler = crawler->children[index];
        }
        return true; 
    }

    bool deleteWord(trieNode* root, string word, int depth = 0) {
        if (!root) {
            return false;
        }
        if (depth == word.size()) {
            if (root->endOfWord) {
                root->endOfWord = false;
                return isEmpty(root);  
            }
            return false;
        }
        int index = getIndex(word[depth]);
        if (deleteWord(root->children[index], word, depth + 1)) {
            delete root->children[index];
            root->children[index] = NULL;
            return !root->endOfWord && isEmpty(root);
        }
        return false;
    }

    bool isEmpty(trieNode* root) {
        for (int i = 0; i < 26; i++) {
            if (root->children[i] != NULL) {
                return false;
            }
        }
        return true;
    }

    void display() {
        displayUtil(root, "");
    }
};

class Solution {
vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
vector<string> result;
int m, n;
    void findWords(vector<vector<char>>& board, int i, int j, Trie::trieNode* root, string s) {
        if(i < 0 || i >= m || j < 0 || j >= n)
            return;
        
        char ch = board[i][j];
        int idx = ch-'a';
        if(board[i][j] == '$' || root->children[idx] == NULL)
            return;
        
        root = root->children[idx];
        s.push_back(ch);
        if(root->endOfWord == true) {
            result.push_back(s);
            root->endOfWord = false;
        }
        
        char temp = board[i][j];
        board[i][j] = '$';
        for(vector<int>& dir : directions) {
            int new_i = i + dir[0];
            int new_j = j + dir[1];
            
            findWords(board, new_i, new_j, root, s);
        }
        board[i][j] = temp;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        m = board.size();
        n = board[0].size();
        for (string& word : words) {
            trie.insert(word);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                char ch = board[i][j];
                int idx = ch - 'a';
                string s = "";
                if (trie.root->children[idx] != NULL)
                    findWords(board, i, j, trie.root, s);
            }
        }

        return result;
    }
};