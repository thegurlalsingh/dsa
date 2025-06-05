class Solution {
public:
    vector<int> parent;
    
    int find(int i) {
        if(parent[i] != i)
            parent[i] = find(parent[i]);
        
        return parent[i];
    }
    
    void Union(int x, int y) {
        int p_x = find(x);
        int p_y = find(y);
        
        if(p_x != p_y) {
            if(p_x < p_y) {
                parent[p_y] = p_x;
            } else if(p_y > p_x) {
                parent[p_x] = p_y;
            } else {
                parent[p_x] = p_y;
            }
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        parent.resize(26);
        int n = s1.length();
        for(int i = 0; i<26; i++) {
            parent[i] = i;
        }
        for(int i = 0; i < n; i++){
            Union(s1[i] - 'a', s2[i] - 'a');
        }
        string res = "";
        for(int i = 0; i < baseStr.length(); i++){
            int d = find(baseStr[i] - 'a');
            char a = d + 'a';
            res += a;
        }
        return res;
    }
};