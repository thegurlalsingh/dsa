class Solution {
    int helper(string s , string t){
        int cnt = 0 , m = s.size();
        multiset<pair<char ,char>> st;
        for(int ind = 0 ; ind < m ; ind++){
            if(s[ind] != t[ind]){
                auto it = st.find({t[ind] , s[ind]});
                if(it != st.end()){
                    st.erase(it);
                    cnt++;
                }
                else {
                    st.insert({s[ind] , t[ind]});
                }
            }
        }
        return cnt + (int)st.size();
    }

    int cost(string &sub1, string &sub2){
        int n = sub1.size();

        int mismatches = 0;
        for(int i = 0; i < n; i++){
            if(sub1[i] != sub2[i]) mismatches++;
        }

        int ans = INT_MAX;

        // 1. replace
        ans = min(ans, mismatches);

        // 2. swap
        int swap_c = helper(sub1, sub2);
        if(swap_c != INT_MAX) ans = min(ans, swap_c);

        // 3. reverse
        string rev = sub1;
        reverse(rev.begin(), rev.end());

        if(rev == sub2){
            ans = min(ans, 1);
        }

        // mismatches after reverse
        int mismatches_rev = 0;
        for(int i = 0; i < n; i++){
            if(rev[i] != sub2[i]) mismatches_rev++;
        }

        // 4. reverse + replace
        ans = min(ans, 1 + mismatches_rev);

        // 5. reverse + swap
        int rev_swap = helper(rev, sub2);
        if(rev_swap != INT_MAX){
            ans = min(ans, 1 + rev_swap);
        }

        return ans;
    }

    vector<int> dp;

    int solve(int i, string &word1, string &word2, int n){
        if(i >= n) return 0;

        if(dp[i] != -1) return dp[i];

        int ans = INT_MAX;

        for(int j = i; j < n; j++){
            string sub1 = word1.substr(i, j - i + 1);
            string sub2 = word2.substr(i, j - i + 1);

            int curr = cost(sub1, sub2);
            ans = min(ans, curr + solve(j + 1, word1, word2, n));
        }

        return dp[i] = ans;
    }

public:
    int minOperations(string word1, string word2) {
        int n = word1.size();
        dp.assign(n, -1);
        return solve(0, word1, word2, n);
    }
};