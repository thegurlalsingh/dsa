class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n = costs.size();
        vector<pair<int,int>> machines(n);

        for (int i = 0; i < n; i++) {
            machines[i] = {costs[i], capacity[i]};
        }

        sort(machines.begin(), machines.end());

        int ans = 0;

        // one machine
        for (int i = 0; i < n; i++) {
            if (machines[i].first < budget) {
                ans = max(ans, machines[i].second);
            }
        }

        // prefix max of capacities
        vector<int> prefixmax(n);
        prefixmax[0] = machines[0].second;
        for (int i = 1; i < n; i++) {
            prefixmax[i] = max(prefixmax[i - 1], machines[i].second);
        }

        // two machines using lower_bound
        for (int r = 1; r < n; r++) {
            int remaining = budget - machines[r].first;
            if (remaining <= 0) continue;

            auto it = lower_bound(machines.begin(), machines.begin() + r, make_pair(remaining, INT_MIN));

            if (it != machines.begin()) {
                --it;
                int idx = it - machines.begin();
                ans = max(ans, prefixmax[idx] + machines[r].second);
            }
        }

        return ans;
    }
};
