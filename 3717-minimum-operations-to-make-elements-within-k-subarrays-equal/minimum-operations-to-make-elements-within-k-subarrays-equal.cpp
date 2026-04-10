#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        vector<long long> ops(n - x + 1);
        ordered_set<pair<int, int>> st;
        long long sum = 0, half_sum = 0;
        
        auto Replace = [&](int erase, int insert) -> void {
            if(insert == n) return;
            int erase_pos = st.order_of_key({nums[erase], erase});
            st.erase({nums[erase], erase});
            st.insert({nums[insert], insert});
            int insert_pos = st.order_of_key({nums[insert], insert});
            
            if(erase_pos < (x + 1) / 2) {
                half_sum -= nums[erase];
                if(insert_pos < (x + 1) / 2) half_sum += nums[insert];
                else half_sum += st.find_by_order((x - 1) / 2)->first;
            }else if(insert_pos < (x + 1) / 2) {
                half_sum = half_sum - st.find_by_order((x + 1) / 2)->first + nums[insert];
            }
            sum = sum - nums[erase] + nums[insert];
        };
        auto Median = [&]() -> int {
            if(x % 2 == 0) {
                auto it = st.find_by_order((x - 1) / 2);
                return (it->first + next(it)->first) / 2;
            }else {
                return st.find_by_order(x / 2)->first;
            }
        };
        
        for(int i = 0; i < x; i++) {
            st.insert({nums[i], i});
            sum += nums[i];
        }
        auto it = st.begin();
        for(int i = 0; i < (x + 1) / 2; i++, it++) {
            half_sum += it->first;   
        }
        for(int i = 0; i <= (n - x); i++) {
            long long med = Median();
            ops[i] =
                (med * ((x + 1) / 2)) - half_sum +
                (sum - half_sum) - (med * (x - (x + 1) / 2));
            Replace(i, i + x);
        }
        
        static long long dp[100001][16];
        for(int i = n; i >= 0; i--) {
            for(int subarr = k; subarr >= 0; subarr--) {
                if(subarr == k) {
                    dp[i][subarr] = 0;
                }else if(i == n) {
                    dp[i][subarr] = 1e18;
                }else {
                    dp[i][subarr] = dp[i + 1][subarr];
                    if(i + x <= n)
                        dp[i][subarr] = min(dp[i][subarr], ops[i] + dp[i + x][subarr + 1]);
                }
            }
        }
        
        return dp[0][0];
    }
};