class Solution {
public:
    string generateString(string str1, string str2) {
        string words;
        int n = str1.size();
        int m = str2.size();
        int i=0;
        map<int,int>mp;
        while(i<n){
            if(str1[i]=='F'){
                if(i>=words.size()){
                    words+='a';
                    mp[words.size()-1]=1;    
                }
            }
            else{
                for(int j=i;j<i+m;j++){
                    if(j>=words.size()){
                        words+=str2[j-i];
                    }
                    else if(words[j]!=str2[j-i]){
                        return "";
                    }
                }
            }
            i++;
        }
        while(words.size()<n+m-1){
            words+='a';
            mp[words.size()-1]=1;
        }
        bool loop = 1;
        while(loop){
            loop = 0;
            for(int i=0;i<str1.size();i++){
                if(str1[i]=='F'){
                    bool need = true;
                    for(int j=i; j<i+m;j++){
                        if(str2[j-i]!=words[j]){
                            need = false;
                            break;
                        }
                    }
                    if(need){
                        bool done = false;
                        for(int j=i+m-1;j>=i;j--){
                            if(mp[j]==1){
                               if(words[j]!='z'){
                                    done = true;
                                    words[j]++;
                                    loop =1;
                                    break;
                               }
                            }
                        }
                        if(!done){
                            return "";
                        }
                        else{
                            break;
                        }
                    }
                }
            }
        }
        return words;
    }
};