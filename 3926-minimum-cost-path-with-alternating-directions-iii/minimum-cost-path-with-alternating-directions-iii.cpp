typedef tuple<long long, int, int, int> T; // cost, i, j, chance

class Solution {
public:
    long long minCost(int m, int n, vector<vector<int>>& penalty) {
        priority_queue<T, vector<T>, greater<T>> pq;

        vector<vector<vector<long long>>> cost(
            m, vector<vector<long long>>(n, vector<long long>(2, LLONG_MAX)));

        pq.push({1, 0, 0, 1});
        cost[0][0][1] = 1;

        while (!pq.empty()) {
            auto [c, i, j, chance] = pq.top();
            pq.pop();

            int wait_cost = penalty[i][j];

            if (chance % 2 == 1) {

                if (i + 1 < m &&
                    c + ((i + 2) * (j + 1)) < cost[i + 1][j][(chance + 1) % 2]) {

                    pq.push({c + ((i + 2) * (j + 1)), i + 1, j, chance + 1});
                    cost[i + 1][j][(chance + 1) % 2] =
                        c + ((i + 2) * (j + 1));
                }

                if (j + 1 < n &&
                    c + ((i + 1) * (j + 2)) < cost[i][j + 1][(chance + 1) % 2]) {

                    pq.push({c + ((i + 1) * (j + 2)), i, j + 1, chance + 1});
                    cost[i][j + 1][(chance + 1) % 2] =
                        c + ((i + 1) * (j + 2));
                }

                if (i - 1 >= 0 &&
                    c + penalty[i][j] + (i * (j + 1)) <
                        cost[i - 1][j][(chance + 1) % 2]) {

                    pq.push(
                        {c + penalty[i][j] + (i * (j + 1)), i - 1, j, chance + 1});
                    cost[i - 1][j][(chance + 1) % 2] =
                        c + penalty[i][j] + (i * (j + 1));
                }

                if (j - 1 >= 0 &&
                    c + penalty[i][j] + ((i + 1) * j) <
                        cost[i][j - 1][(chance + 1) % 2]) {

                    pq.push(
                        {c + penalty[i][j] + ((i + 1) * j), i, j - 1, chance + 1});
                    cost[i][j - 1][(chance + 1) % 2] =
                        c + penalty[i][j] + ((i + 1) * j);
                }

                if (c + wait_cost < cost[i][j][(chance + 1) % 2]) {
                    pq.push({c + wait_cost, i, j, chance + 1});
                    cost[i][j][(chance + 1) % 2] = c + wait_cost;
                }

            } else {

                if (i + 1 < m &&
                    c + penalty[i][j] + ((i + 2) * (j + 1)) <
                        cost[i + 1][j][(chance + 1) % 2]) {

                    pq.push(
                        {c + penalty[i][j] + ((i + 2) * (j + 1)), i + 1, j,
                         chance + 1});
                    cost[i + 1][j][(chance + 1) % 2] =
                        c + penalty[i][j] + ((i + 2) * (j + 1));
                }

                if (j + 1 < n &&
                    c + penalty[i][j] + ((i + 1) * (j + 2)) <
                        cost[i][j + 1][(chance + 1) % 2]) {

                    pq.push(
                        {c + penalty[i][j] + ((i + 1) * (j + 2)), i, j + 1,
                         chance + 1});
                    cost[i][j + 1][(chance + 1) % 2] =
                        c + penalty[i][j] + ((i + 1) * (j + 2));
                }

                if (i - 1 >= 0 &&
                    c + (i * (j + 1)) < cost[i - 1][j][(chance + 1) % 2]) {

                    pq.push({c + (i * (j + 1)), i - 1, j, chance + 1});
                    cost[i - 1][j][(chance + 1) % 2] =
                        c + (i * (j + 1));
                }

                if (j - 1 >= 0 &&
                    c + ((i + 1) * j) < cost[i][j - 1][(chance + 1) % 2]) {

                    pq.push({c + ((i + 1) * j), i, j - 1, chance + 1});
                    cost[i][j - 1][(chance + 1) % 2] =
                        c + ((i + 1) * j);
                }

                if (c + wait_cost < cost[i][j][(chance + 1) % 2]) {
                    pq.push({c + wait_cost, i, j, chance + 1});
                    cost[i][j][(chance + 1) % 2] = c + wait_cost;
                }
            }
        }

        return min(cost[m - 1][n - 1][0], cost[m - 1][n - 1][1]);
    }
};