class Solution {
public:
    int numberOfSubstrings(string s) {
        int i = 0;
        int j = 0;
        int a = 0;
        int b = 0;
        int c = 0;
        int n = s.size();
        int count = 0;
        while(j < n){
            if(s[j] == 'a'){
                a++;
            }
            else if(s[j] == 'b'){
                b++;
            }
            else{
                c++;
            }
            while((a >= 1) && (b >= 1) && (c >= 1)){
                int temp = 0;
                temp = n - j;
                count += temp;
                if(s[i] == 'a'){
                    a--;
                }
                else if(s[i] == 'b'){
                    b--;
                }
                else{
                    c--;
                }
                i++;
            }
            j++; 
        }
        return count;
    }
};