#include <bits/stdc++.h>
using namespace std;

struct KeyHash {
    size_t operator()(const tuple<int,int,int>& t) const noexcept {
        auto [a,b,c] = t;
        return (a * 729 + (b+1)*27 + (c+1)); // compact hash
    }
};

class Solution {
    vector<pair<int,int>> pos;
    int dist(int a, int b) {
        if (a == -1 || b == -1) return 0;
        auto [x1, y1] = pos[a];
        auto [x2, y2] = pos[b];
        return abs(x1 - x2) + abs(y1 - y2);
    }

public:
    Solution() {
        pos.resize(26);
        string keys = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        int k = 0;
        for (int i=0;i<5;i++){
            for (int j=0;j<6;j++){
                if (k>=26) break;
                pos[keys[k]-'A'] = {i,j};
                k++;
            }
        }
    }

    int minimumDistance(string word) {
        int n = word.size();
        queue<tuple<int,int,int,int>> q; // i, f1, f2, cost
        unordered_map<tuple<int,int,int>, int, KeyHash> dp;

        q.push({0, -1, -1, 0});
        dp[{0,-1,-1}] = 0;

        int ans = INT_MAX;

        while(!q.empty()){
            auto [i,f1,f2,cost] = q.front();
            q.pop();

            if(i == n){
                ans = min(ans, cost);
                continue;
            }

            int cur = word[i]-'A';

            // Use finger 1
            int c1 = cost + dist(f1, cur);
            auto key1 = make_tuple(i+1, cur, f2);
            if(!dp.count(key1) || c1 < dp[key1]){
                dp[key1] = c1;
                q.push({i+1, cur, f2, c1});
            }

            // Use finger 2
            int c2 = cost + dist(f2, cur);
            auto key2 = make_tuple(i+1, f1, cur);
            if(!dp.count(key2) || c2 < dp[key2]){
                dp[key2] = c2;
                q.push({i+1, f1, cur, c2});
            }
        }

        return ans;
    }
};

