#include <bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> parent, rank;
public:
    DisjointSet(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUPar(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int pu = findUPar(u);
        int pv = findUPar(v);
        if (pu == pv) return;
        if (rank[pu] < rank[pv]) parent[pu] = pv;
        else if (rank[pv] < rank[pu]) parent[pv] = pu;
        else {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
};

class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        DisjointSet dsu(n);

        stack<int> st;

        // Pass 1: Left to Right (forward jumps: nums[j] < nums[i])
        // for (int i = 0; i < n; i++) {
        //     int prev = i;
        //     while (!st.empty() && nums[st.top()] > nums[i]) {
        //         dsu.unionByRank(i, st.top());
        //         prev = st.top();
        //         st.pop();
        //     }
        //     if (nums[prev] < nums[i]) st.push(i);
        //     else st.push(prev);
        // }

        // while (!st.empty()) st.pop();

        // Pass 2: Right to Left (backward jumps: nums[j] > nums[i])
        // for (int i = n - 1; i >= 0; i--) {
        //     int prev = i;
        //     while (!st.empty() && nums[st.top()] < nums[i]) {
        //         dsu.unionByRank(i, st.top());
        //         prev = st.top();
        //         st.pop();
        //     }
        //     if (nums[prev] > nums[i]) st.push(i);
        //     else st.push(prev);
        // }

        for(int i = 0; i < n; i++){
            int x = i;
            while(!st.empty() && nums[st.top()] > nums[i]){
                if(nums[st.top()] > nums[x]) x = st.top();
                dsu.unionByRank(st.top(), i);
                st.pop();
            }
            dsu.unionByRank(x, i);
            st.push(x);
        }

        while (!st.empty()) st.pop();

        for(int i = n - 1; i >= 0; i--){
            int x = i;
            while(!st.empty() && nums[st.top()] < nums[i]){
                if(nums[st.top()] > nums[x]) x = st.top();
                dsu.unionByRank(st.top(), i);
                st.pop();
            }
            dsu.unionByRank(x, i);
            st.push(x);
        }

        // Group indices by component
        vector<vector<int>> groups(n);
        for (int i = 0; i < n; i++) {
            groups[dsu.findUPar(i)].push_back(i);
        }

        // Assign max per component
        vector<int> ans(n);
        for (auto &comp : groups) {
            if (comp.empty()) continue;
            int maxi = INT_MIN;
            for (int idx : comp) maxi = max(maxi, nums[idx]);
            for (int idx : comp) ans[idx] = maxi;
        }

        return ans;
    }
};
