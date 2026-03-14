typedef long long ll;
class Solution {
public:
    char processStr(string s, long long k) {
        //store values of type (special, char, len)
       vector<tuple<char,char,ll>>v;
        ll currlen=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            char c=s[i];
            if(c=='*'){
                //deleted something
                if(currlen>0)currlen--;
                v.push_back(make_tuple('*',0,currlen));
            }
            else if(c=='#'){
                currlen=min(currlen*2,LLONG_MAX);
                v.push_back(make_tuple('#',0,currlen));
            }
            // if % we will reverse based on index dont do anything here len remain same
            else if(c=='%'){
               v.push_back(make_tuple('%',0,currlen)); 
            }
            else {
                currlen++;
                v.push_back(make_tuple('c',c,currlen));
            }
        }


        if(k>=currlen)return '.';

        for(int i=n-1;i>=0;i--){
            char special=get<0>(v[i]);
            char c=get<1>(v[i]);
            ll len=get<2>(v[i]);

            if(special=='c'){
                if(k==len-1)return c;
            }
            // deleted something this skip
            else if(special=='*')continue;
            else if(special=='#'){
                ll half=len/2;
                if(k>=half)k-=half;
            }
            else if(special=='%'){
                k=len-1-k;
            }
        }
        return '.';
    }
};