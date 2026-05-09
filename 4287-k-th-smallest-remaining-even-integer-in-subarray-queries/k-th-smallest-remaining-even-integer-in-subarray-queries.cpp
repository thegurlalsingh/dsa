class Solution {
    vector<int> pref;

    long long kthSmallest(vector<int>& nums, int l, int r, long long k) {

        auto check = [&](long long mid) {

            long long totalEven = mid / 2;

            int idx = upper_bound(nums.begin() + l,
                                  nums.begin() + r + 1,
                                  mid) - nums.begin();

            long long removed = pref[idx] - pref[l];

            return totalEven - removed;
        };

        long long low = 2, high = 1e18;
        long long ans = -1;

        while (low <= high) {

            long long mid = low + (high - low) / 2;

            if (check(mid) >= k) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        if (ans & 1) ans--;

        return ans;
    }
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int n = nums.size();
        pref.assign(n + 1, 0);

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] + (nums[i] % 2 == 0);
        }

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];
            long long k = q[2];

            ans.push_back(kthSmallest(nums, l, r, k));
        }

        return ans;
    }
};