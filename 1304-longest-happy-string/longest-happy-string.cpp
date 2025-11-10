class Solution {
public:
    
    int dp[101][101][101][4];
    int f(int a, int b, int c, int p){
        if(dp[a][b][c][p] != -1) return dp[a][b][c][p];

        int f1,f2,f3,f4,f5,f6; 
        f1=f2=f3=f4=f5=f6=0;
        // take 1 char
        if(a>0 and p!=1) f1 = 1 + f(a-1, b,   c,   1);
        if(b>0 and p!=2) f2 = 1 + f(a,   b-1, c,   2);
        if(c>0 and p!=3) f3 = 1 + f(a,   b,   c-1, 3);

        // take 2 char
        if(a>1 and p!=1) f4 = 2 + f(a-2, b,   c,   1);
        if(b>1 and p!=2) f5 = 2 + f(a,   b-2, c,   2);
        if(c>1 and p!=3) f6 = 2 + f(a,   b,   c-2, 3);

        return dp[a][b][c][p] = max({f1,f2,f3,f4,f5,f6});
    }

    string longestDiverseString(int a, int b, int c) {
        memset(dp,-1,sizeof(dp));
        cout <<  f(a,b,c,0);    
        buildString(a,b,c,0);   
        return maxLenString;
    }

    string maxLenString;
    void buildString(int a, int b, int c, int p) {
        // Base case: if no characters are left
        if (a == 0 && b == 0 && c == 0) return;

        // Check which option was chosen based on previous state
        if (p != 1 && a > 0 && dp[a][b][c][p] == 1 + dp[a-1][b][c][1]) {
            maxLenString += 'a';
            buildString(a - 1, b, c, 1);
            return;
        }
        if (p != 2 && b > 0 && dp[a][b][c][p] == 1 + dp[a][b-1][c][2]) {
            maxLenString += 'b';
            buildString(a, b - 1, c, 2);
            return;
        }
        if (p != 3 && c > 0 && dp[a][b][c][p] == 1 + dp[a][b][c-1][3]) {
            maxLenString += 'c';
            buildString(a, b, c - 1, 3);
            return;
        }

        // Check for taking two characters
        if (p != 1 && a > 1 && dp[a][b][c][p] == 2 + dp[a-2][b][c][1]) {
            maxLenString += "aa";
            buildString(a - 2, b, c, 1);
            return;
        }
        if (p != 2 && b > 1 && dp[a][b][c][p] == 2 + dp[a][b-2][c][2]) {
            maxLenString += "bb";
            buildString(a, b - 2, c, 2);
            return;
        }
        if (p != 3 && c > 1 && dp[a][b][c][p] == 2 + dp[a][b][c-2][3]) {
            maxLenString += "cc";
            buildString(a, b, c - 2, 3);
            return;
        }
    }
};