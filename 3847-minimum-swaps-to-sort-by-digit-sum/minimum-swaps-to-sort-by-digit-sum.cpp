typedef tuple<int, int> P;

class Solution {
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

public:
    int minSwaps(vector<int>& nums) {
        unordered_map<int, int> mp;
        unordered_map<int, int> idxOriginal;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = digitSum(nums[i]);
            idxOriginal[nums[i]] = i;
        }

        priority_queue<P, vector<P>, greater<P>> pq;

        for (int i = 0; i < nums.size(); i++) {
            pq.push({mp[nums[i]], nums[i]});
        }

        vector<pair<int, int>> f;

        while (!pq.empty()) {
            auto [s, e] = pq.top();
            pq.pop();
            f.push_back({s, e});
        }

        int ans = 0;

        for (int i = 0; i < f.size(); i++) {
            if (idxOriginal[f[i].second] == i) {
                continue;
            }

            int j = idxOriginal[f[i].second];

            // Find the element currently at index i
            int other = nums[i];

            swap(nums[i], nums[j]);

            // Update the indices after swapping
            idxOriginal[f[i].second] = i;
            idxOriginal[other] = j;

            ans++;
        }

        return ans;
    }
};