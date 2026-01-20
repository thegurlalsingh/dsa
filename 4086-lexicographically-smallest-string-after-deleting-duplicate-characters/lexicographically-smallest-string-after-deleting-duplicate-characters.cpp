class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        int n = (int)s.size();
        int lastOcc[26];
        memset(lastOcc, -1, sizeof(lastOcc));
        for(int i = 0; i < n; i ++){
            lastOcc[s[i] - 'a'] = i;
        }
        int nextOcc[n + 1][26];
        memset(nextOcc, -1, sizeof(nextOcc));
        for(int i = n - 1; i >= 0; i --){
            for(int j = 0; j < 26; j ++){
                nextOcc[i][j] = nextOcc[i + 1][j];
            }
            nextOcc[i][s[i] - 'a'] = i;
        }
        bool removable[n];
        memset(removable, false, sizeof(removable));
        for(int i = 0; i < n; i ++){
            if(lastOcc[s[i] - 'a'] > i){
                removable[i] = true;
            }
        }
        
        bool added[26];
        memset(added, false, sizeof(added));
        string ret = "";
        
        //i IS BASICALLY THE NEXT CHARACTER THAT WE HAVE NOT CONSIDERED
        int i = 0;
        while(i < n){
            bool c_inserted = false;
            
            //CAN WE STOP ADDING CHARACTERS - SHORTER THE BETTER:
            bool end_here = true;
            for(int c = 0; c < 26; c ++){
                if(lastOcc[c] == -1) continue;
                if(added[c]) continue;
                end_here = false;
            }
            if(end_here){
                break;
            }

            //GREEDY - CONSIDER FROM SMALLEST TO LARGEST CHARACTER
            for(int c = 0; c < 26; c ++){
                if(nextOcc[i][c] == -1) continue;
                
                bool ok = true;
                for(int j = i; j < nextOcc[i][c]; j ++){
                    if(removable[j] || added[s[j] - 'a']) continue;
                    ok = false;
                    break;
                }
                if(ok){
                    ret += (char)(c + 'a');
                    added[c]   = true;
                    c_inserted = true;
                    i = nextOcc[i][c] + 1;
                    break;
                }
            }
            if(!c_inserted){
                break;
            }
        }
        return ret;
    }
};