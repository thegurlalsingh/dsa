class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size(); //length of string
         //l is left pointer,r is right pointer and total counts total number of substrings
        int l=0,r=0,cnta=0,cntb=0,cntc=0,total=0;
        while(r<n){ //update the cnts
            if(s[r]=='a') cnta++;
           else if(s[r]=='b') cntb++;
            else cntc++;
            //shrink while this window is valid
             while(cnta>=1 && cntb>=1 && cntc>=1){
                total+=n-r; //becuase all substrings from n-r are valid
               //start shrinking from left
                if(s[l]=='a') cnta--;
           else if(s[l]=='b') cntb--;
            else cntc--;
            l++;
             }
//increment the right pointer
             r++;
        }
//return total number of substrings
        return total;
    }
};