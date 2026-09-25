class Trie{
    public:
    struct Node {
        Node* child[26]; bool isEnd;
        Node(){
            isEnd = false;
            for(int i = 0; i < 26; i++){
                child[i] = nullptr;
            }
        }
    };

    Node* root;

    Trie(){
        root = new Node();
    }

    void insert(string word){
        Node* curr = root;
        for(char ch : word){
            int idx = ch - 'a';
            if(curr->child[idx] == nullptr){
                curr->child[idx] = new Node();
            }
            curr = curr->child[idx];
        }
        curr->isEnd = true;
    }

    bool search(string word){
        Node* curr = root;
        
        for(int i = 0; i < word.size(); i++){
            if(word[i] == '.'){
                for(char j = 'a'; j <= 'z'; j++){
                    string s = word;
                    s[i] = j;
                    if(search(s)){
                        return true;
                    }
                }
                return false;
            }
            int idx = word[i] - 'a';
            if(curr->child[idx] == nullptr){
                return false;
            }
            curr = curr->child[idx];
        }
        return curr->isEnd;
    }

    // bool dfs(string& s){

    // }
};


class WordDictionary {
public:
    Trie t;
    WordDictionary() {
        
    }
    
    void addWord(string word) {
        t.insert(word);
    }
    
    bool search(string word) {
        return t.search(word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */