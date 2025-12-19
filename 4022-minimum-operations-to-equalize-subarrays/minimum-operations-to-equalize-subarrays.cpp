class Query {
    public:
    int l, r, idx;
};

class Solution {
public:
    typedef long long ll;
    ll leftSum, rightSum;
    multiset<int> left, right;
    
    // ⚖️ Balances the two sets so Left has the median
    void rebalance() {
        // If Left is too big, move largest to Right
        while(left.size() > right.size() + 1) {
            auto it = prev(left.end());
            ll val = *it;
            leftSum -= val;
            left.erase(it);
            
            rightSum += val;
            right.insert(val);
        }

        // If Right is bigger, move smallest to Left
        while(left.size() < right.size()) {
            auto it = right.begin();
            ll val = *it;
            rightSum -= val;
            right.erase(it);
            
            leftSum += val;
            left.insert(val);
        }
    }

    void add(int i, vector<int>& nums) {
        // Always try to put in Left first if it belongs there
        if(left.empty() || nums[i] <= *left.rbegin()) {
            left.insert(nums[i]);
            leftSum += nums[i];
        } else {
            right.insert(nums[i]);
            rightSum += nums[i];
        }
        rebalance();
    }

    void remove(int i, vector<int>& nums) {
        // Find and remove the element from the correct set
        auto it = left.find(nums[i]);
        if(it != left.end()) {
            leftSum -= nums[i];
            left.erase(it);
        } else {
            it = right.find(nums[i]);
            rightSum -= nums[i];
            right.erase(it);
        }
        rebalance();
    }

    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();

        // 🔍 Precompute validity check
        vector<int> lastMatchIdx(n);
        lastMatchIdx[n - 1] = n - 1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] % k == nums[i + 1] % k) {
                lastMatchIdx[i] = lastMatchIdx[i + 1];
            } else {
                lastMatchIdx[i] = i;
            }
        }

        int q = queries.size();
        vector<Query> offline_queries;
        vector<ll> answer(q);
        
        // ⚡ Filter invalid queries upfront to save time
        for(int i = 0; i < q; i++) {
            int l = queries[i][0];
            int r = queries[i][1];

            if (lastMatchIdx[l] < r) {
                answer[i] = -1; 
            } else {
                offline_queries.push_back({l, r, i}); 
            }
        }

        // 📉 Mo's Algorithm Sort
        const int BLOCK_SIZE = max(1, (int)(n / sqrt(offline_queries.size() + 1)));
        auto cmp = [&](Query &q1, Query& q2) {
            if(q1.l / BLOCK_SIZE == q2.l / BLOCK_SIZE) {
                return q1.r < q2.r;
            }
            return q1.l / BLOCK_SIZE < q2.l / BLOCK_SIZE;
        };
        sort(offline_queries.begin(), offline_queries.end(), cmp);

        int i = 0, j = -1;
        left.clear(); right.clear();
        leftSum = 0; rightSum = 0;
        
        // 🏃 Process Queries
        for(auto &query : offline_queries) {
            int l = query.l;
            int r = query.r;
            int idx = query.idx;

            // Expand range
            while(j < r) add(++j, nums);
            while(i > l) add(--i, nums);
    
            // Shrink range
            while(j > r) remove(j--, nums);
            while(i < l) remove(i++, nums);

            // Calculate Answer
            // Since we filtered invalid queries, we know this is valid!
            ll median = *prev(left.end());
            ll leftOps = left.size() * median - leftSum;
            ll rightOps = rightSum - right.size() * median;
            ll totalOps = leftOps + rightOps;
            answer[idx] = totalOps / k;
        }
        return answer;
    }
};