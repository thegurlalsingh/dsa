class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int, int>> a; 
        int k = nums.size();

        for (int i = 0; i < k; i++) {
            for (int val : nums[i]) {
                a.push_back({val, i});
            }
        }

        sort(a.begin(), a.end());

        unordered_map<int, int> freq;
        int x = 0, y = 0;
        int count = 0; 
        int minRange = INT_MAX;
        int start = -1;
        int end = -1;

        while (y < a.size()) {
            int listId = a[y].second;
            freq[listId]++;
            if (freq[listId] == 1) {
                count++; 
            }

            while (count == k && x <= y) {
                int range = a[y].first - a[x].first;
                if (range < minRange) {
                    minRange = range;
                    start = a[x].first;
                    end = a[y].first;
                }

                int leftListId = a[x].second;
                freq[leftListId]--;
                if (freq[leftListId] == 0) {
                    count--; 
                }
                x++;
            }

            y++;
        }

        return {start, end};
    }
};
