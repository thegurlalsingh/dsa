class Trie {
public:
    struct Node {
        Node* child[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++) {
                child[i] = nullptr;
            }
        }
    };

    Node* root;

    Trie() { root = new Node(); }

    void insert(string word) {
        Node* curr = root;

        for (char ch : word) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr) {
                curr->child[idx] = new Node();
            }

            curr = curr->child[idx];
        }

        curr->isEnd = true;
    }

    string startsWith(string prefix) {
        string s = "";
        Node* curr = root;

        for (char ch : prefix) {
            int idx = ch - 'a';

            if (curr->child[idx] == nullptr) {
                return "";
            }
            
            s.push_back(ch);
            curr = curr->child[idx];
            if(curr->isEnd) {
                return s;
            } // early return because we have to choose smallest root and if this is ending early, it means it is smallest
        }

        return s;
    }
};

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie t;
        for (int i = 0; i < dictionary.size(); i++) {
            t.insert(dictionary[i]);
        }
        vector<string> st;
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            st.push_back(word);
        }
        for(int i = 0; i < st.size(); i++){
            string k = st[i];
            if(t.startsWith(st[i]) != ""){
                k = t.startsWith(st[i]);
            }
            st[i] = k;
        }
        string ans = "";
        for(int i = 0; i < st.size(); i++){
            ans += st[i]; 
            ans.push_back(' ');
        }
        ans.pop_back();
        return ans;
    }
};