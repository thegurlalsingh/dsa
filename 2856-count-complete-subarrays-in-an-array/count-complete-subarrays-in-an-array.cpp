class Solution {
private:
    int atmost(vector<int>& nums, int k){
        int i = 0, j = 0, n = nums.size();
        unordered_map<int, int> m;
        int count = 0;

        while(j < n){
            m[nums[j]]++;

            while(m.size() > k){
                m[nums[i]]--;
                if(m[nums[i]] == 0)
                    m.erase(nums[i]);
                i++;
            }

            count += j - i + 1;
            j++;
        }

        return count;
    }

public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int k = s.size();
        return atmost(nums, k) - atmost(nums, k - 1);
    }
};