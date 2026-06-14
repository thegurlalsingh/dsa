class Trie {
    struct Node {
        Node* links[26];
        bool isEnd;
        int i;
        Node() {
            for (int i = 0; i < 26; i++) {
                links[i] = nullptr;
            }
            isEnd = false;
            i = -1;
        }
    };

    Node* root;

public:
    Trie() { root = new Node(); }

    void insert(string word, int index) {
        Node* node = root;
        for (char ch : word) {
            int idx = ch - 'a';
            if (node->links[idx] == nullptr) {
                node->links[idx] = new Node();
            }
            node = node->links[idx];
        }
        node->isEnd = true;
        node->i = index;
    }

    Node* startsWith(string prefix) {
        Node* node = root;
        string ans = "";
        for(char ch : prefix) {
            int idx = ch - 'a';
            if(node->links[idx] == NULL)
                return new Node();
            ans += ch;
            node = node->links[idx];
            if(node->isEnd){
                return node;
            }
        }

        return node;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;

        for(int i = 0; i < dictionary.size(); i++){
            t.insert(dictionary[i], i);
        }

        stringstream ss(sentence);

        string word;

        vector<string> v;

        while(ss >> word){
            v.push_back(word);
        }

        string k = "";

        for(int i = 0; i < v.size(); i++){
            int index = t.startsWith(v[i])->i;
            if(index != -1){
                v[i] = dictionary[index];
            }

            k += v[i];
            if(i != v.size() - 1){
                k += ' ';
            }
        }

        return k;
    }
};