using t = tuple<double, int, int>;
class Solution {
    struct compare {
        bool operator()(auto a, auto b) {
            auto [p1, p2, p3] = a;
            auto [v1, v2, v3] = b;
            if (abs(p1 - v1) < 1e-9)
                return p2 > v2; // min price
            return p1 < v1;     // maxheap
        }
    };

public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        priority_queue<t, vector<t>, compare> pq;
        int n = items.size();
        vector<int> freq(n + 1, 0), freebies(n + 1, 0);
        int minPrice = 1e9;
        for (int i = 0; i < n; i++) {
            freq[items[i][0]]++;
            minPrice = min(minPrice, items[i][1]);
        }
        for (int f = 1; f <= n; f++) {
            if (freq[f] > 0) {
                for (int m = f; m <= n; m = m + f) {
                    freebies[f] += freq[m];
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int units = freebies[items[i][0]] - 1;
            if (units > 0) {
                double perUnit = 2.0 / items[i][1];
                pq.push({perUnit, items[i][1], units});
            }
        }
        int cnt = 0;
        while (!pq.empty() && budget > 0) {
            auto [u, p, c] = pq.top();
            pq.pop();
            if (u < 1.0 / minPrice)
                break;
            int afford = budget / p;
            int buy = min(afford, c);
            if (buy > 0) {
                cnt += buy * 2;
                budget = budget - buy*p;
            }
        }
        cnt += (budget / minPrice);
        return cnt;
    }
};