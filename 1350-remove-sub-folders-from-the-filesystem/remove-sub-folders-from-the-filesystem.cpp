class Trie {
public:
    struct trieNode {
        bool isEndOfWord;
        unordered_map<string, trieNode*> children;
        trieNode() : isEndOfWord(false) {}
    };

    trieNode* root;

    Trie() {
        root = new trieNode();
    }

    vector<string> split(const string& path) {
        vector<string> parts;
        string part;
        for (int i = 1; i < path.size(); ++i) {
            if (path[i] == '/') {
                if (!part.empty()) {
                    parts.push_back(part);
                    part.clear();
                }
            } 
            else {
                part += path[i];
            }
        }
        if (!part.empty()) {
            parts.push_back(part);
        }
        return parts;
    }

    bool subFolder(const vector<string>& parts) {
        trieNode* crawler = root;
        for (const string& part : parts) {
            if (crawler->isEndOfWord) {
                return true;
            }
            if (crawler->children.find(part) == crawler->children.end()) {
                return false;
            }
            crawler = crawler->children[part];
        }
        return false;
    }

    void insert(const string& path) {
        vector<string> parts = split(path);
        if (subFolder(parts)) return;

        trieNode* crawler = root;
        for (const string& part : parts) {
            if (!crawler->children.count(part)) {
                crawler->children[part] = new trieNode();
            }
            crawler = crawler->children[part];
        }
        crawler->isEndOfWord = true;
    }

    void collect(trieNode* node, string path, vector<string>& result) {
        if (node->isEndOfWord) {
            result.push_back(path);
            return;
        }

        for (auto& [segment, child] : node->children) {
            collect(child, path + "/" + segment, result);
        }
    }

    vector<string> getAllFolders() {
        vector<string> result;
        collect(root, "", result);
        return result;
    }
};

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end()); 
        Trie t;
        for (const string& f : folder) {
            t.insert(f);
        }
        return t.getAllFolders();
    }
};
