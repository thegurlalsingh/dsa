class Trie {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for(int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;

    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* curr = root;

        for(char ch : word) {
            int idx = ch - 'a';

            if(curr->child[idx] == nullptr) {
                curr->child[idx] = new Node();
            }

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }
};

class Solution {
    void solve(int i, int j, int m, int n, vector<vector<char>>& board, Trie::Node* node, unordered_set<string>& ans, string build, vector<vector<bool>>& visited){
        if(i >= m || j >= n || i < 0 || j < 0){
            return ;
        }

        if(visited[i][j]) {
            return;
        }

        int idx = board[i][j] - 'a';

        if(node->child[idx] == nullptr){
            return ;
        }

        node = node->child[idx];

        build.push_back(board[i][j]);
    
        if(node->isEnd){
            ans.insert(build);
        }
        
        visited[i][j] = true;

        solve(i, j + 1, m, n, board, node, ans, build, visited);
        
        solve(i + 1, j, m, n, board, node, ans, build, visited);
        
        solve(i - 1, j, m, n, board, node, ans, build, visited);
        
        solve(i, j - 1, m, n, board, node, ans, build, visited);

        visited[i][j] = false;
        
        build.pop_back();
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie t;
        for(int i = 0; i < words.size(); i++){
            t.insert(words[i]);
        }
        unordered_set<string> ans;
        int m = board.size(); int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                solve(i, j, m, n, board, t.root, ans, "", visited);
            }
        }
        vector<string> answer(ans.begin(), ans.end());
        return answer;
    }
};


// Our version everytime does this, so gets mle
// board cell -> build string -> t.search(build) -> start from Trie ROOT -> walk entire build
// Optimized version
// Trie node -> current board character -> node->child[idx] -> next Trie node