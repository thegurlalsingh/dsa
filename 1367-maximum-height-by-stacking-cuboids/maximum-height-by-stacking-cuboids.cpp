class Solution {
    int n;
    vector<vector<int>> cub;
    vector<vector<int>> memo;

    bool canStack(int last, int i) {
        if (last == -1) return true;
        return cub[last][0] >= cub[i][0] &&
               cub[last][1] >= cub[i][1] &&
               cub[last][2] >= cub[i][2];
    }

    int solve(int i, int last) {
        if (i >= n) return 0;

        if (memo[i][last + 1] != -1)
            return memo[i][last + 1];

        int notTake = solve(i + 1, last);

        int take = 0;
        if (canStack(last, i)) {
            take = cub[i][2] + solve(i + 1, i);
        }

        return memo[i][last + 1] = max(take, notTake);
    }

public:
    int maxHeight(vector<vector<int>>& cuboids) {

        // Sort each cuboid internally
        for (auto &c : cuboids)
            sort(c.begin(), c.end());

        // Sort cuboids in descending order
        sort(cuboids.begin(), cuboids.end(), [](auto &a, auto &b){
            if (a[0] != b[0]) return a[0] > b[0];
            if (a[1] != b[1]) return a[1] > b[1];
            return a[2] > b[2];
        });

        cub = cuboids;
        n = cub.size();

        memo.assign(n, vector<int>(n + 1, -1));

        return solve(0, -1);
    }
};
