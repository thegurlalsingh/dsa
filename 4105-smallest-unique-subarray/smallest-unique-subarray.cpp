class Solution {
    bool rolling(int mid, vector<int>& nums){
        const long long BASE = 31;
        const long long MOD = 1e9 + 7;
        long long power = 1;

        int n = nums.size();

        for(int i = 1; i < mid; i++){
            power = (power * BASE) % MOD;
        }

        long long windowHash = 0;
        unordered_map<long long, int> mp;

        for(int i = 0; i < mid; i++){
            windowHash = (windowHash * BASE + nums[i] + 1) % MOD;
        }

        mp[windowHash] = 1;

        for(int i = mid; i < n; i++){
            long long outgoing = nums[i - mid] + 1;
            long long incoming = nums[i] + 1;
            windowHash = (windowHash - outgoing * power % MOD + MOD) % MOD;
            windowHash = (windowHash * BASE + incoming) % MOD;

            mp[windowHash]++;
        }

        for(auto [key, value] : mp){
            if(value == 1){
                return true;
            }
        }

        return false;
    }

public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int length = nums.size();
        int i = 1; int j = length - 1;
        int ans = length;
        while(i <= j){
            int mid = (i + j) / 2;
            if(rolling(mid, nums)){
                ans = mid;
                j = mid - 1;
            }
            else{
                i = mid + 1;
            }
        }
        return ans;
    }
};