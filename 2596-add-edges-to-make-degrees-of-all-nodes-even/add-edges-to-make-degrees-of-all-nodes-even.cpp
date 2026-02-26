class Solution {
public:

    long long encode(int u, int v) {
        return (long long)u * 100000 + v;
    }

    bool edgeExists(int u, int v, unordered_set<long long>& st) {
        return st.count(encode(u, v));
    }

    bool handleTwoOdd(int n, vector<int>& odd, unordered_set<long long>& st) {
        int a = odd[0], b = odd[1];

        // Direct connection possible
        if (!edgeExists(a, b, st)) return true;

        // Try intermediate node
        for (int x = 1; x <= n; x++) {
            if (x != a && x != b &&
                !edgeExists(a, x, st) &&
                !edgeExists(b, x, st)) {
                return true;
            }
        }
        return false;
    }

    bool handleFourOdd(vector<int>& odd, unordered_set<long long>& st) {
        int a = odd[0], b = odd[1], c = odd[2], d = odd[3];

        if (!edgeExists(a,b,st) && !edgeExists(c,d,st)) return true;
        if (!edgeExists(a,c,st) && !edgeExists(b,d,st)) return true;
        if (!edgeExists(a,d,st) && !edgeExists(b,c,st)) return true;

        return false;
    }

    bool isPossible(int n, vector<vector<int>>& edges) {
        vector<int> deg(n+1, 0);
        unordered_set<long long> st;

        for (auto &e : edges) {
            int u = e[0], v = e[1];
            deg[u]++; 
            deg[v]++;
            st.insert(encode(u, v));
            st.insert(encode(v, u));
        }

        vector<int> odd;
        for (int i = 1; i <= n; i++) {
            if (deg[i] % 2) odd.push_back(i);
        }

        int m = odd.size();

        if (m == 0) return true;
        if (m == 2) return handleTwoOdd(n, odd, st);
        if (m == 4) return handleFourOdd(odd, st);

        return false;
    }
};