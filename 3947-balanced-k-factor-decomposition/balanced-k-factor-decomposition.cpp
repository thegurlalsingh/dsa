class Solution {
private:
    vector<int> best;      
    int bestDiff = INT_MAX;

    void solve(vector<int>& divs, vector<int>& curr, int n, int k, int i, long long product) {
        if (curr.size() == k) {
            if (product == n) {
                int mn = *min_element(curr.begin(), curr.end());
                int mx = *max_element(curr.begin(), curr.end());
                if (mx - mn < bestDiff) {
                    bestDiff = mx - mn;
                    best = curr;
                }
            }
            return;
        }

        if (i >= divs.size()) return;

        if (product * divs[i] <= n) {
            curr.push_back(divs[i]);
            solve(divs, curr, n, k, i, product * divs[i]); 
            curr.pop_back();
        }

        solve(divs, curr, n, k, i + 1, product);
    }

public:
    vector<int> minDifference(int n, int k) {
        vector<int> divs;
        for (int i = 1; i <= n; i++) {
            if (n % i == 0) divs.push_back(i);
        }

        vector<int> curr;
        solve(divs, curr, n, k, 0, 1);

        return best.empty() ? vector<int>{} : best;
    }
};
