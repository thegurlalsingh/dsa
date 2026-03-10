class Solution {
public:
    int minOperations(string s) {
        int n = s.size() ; 

        string t = s; 
        sort( t.begin(), t.end() ) ; 
        if( t == s ) return 0 ; 

        if( n == 2 ) return -1 ; 

        string t1 = s, t2 = s ; 
        sort( t1.begin() + 1, t1.end() ) ;
        sort( t2.begin(), t2.end() - 1 ) ; 
        if( t == t1 || t == t2 ) return 1 ; 

        char mini = s[0], maxi = s[0] ;
        map< char, int> M ; 
        for( char ch : s ) {
            M[ch]++ ;
            mini = min(mini, ch ) ;
            maxi = max(maxi, ch ) ; 
        }

        if( maxi == s[0] && mini == s[n-1] && M[mini] == 1 && M[maxi] == 1 ) return 3 ;
        return 2 ; 
    }
};

