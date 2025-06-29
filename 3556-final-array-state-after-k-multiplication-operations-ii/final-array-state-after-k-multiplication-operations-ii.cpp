class Solution {

const long long MOD = 1e9 + 7;

private:
    long long powerMod(long long base, long long exp) {
        long long result = 1;
        base = base % MOD;
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        
        return result;
    }
    
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        if (multiplier == 1) return nums;
        int n = nums.size();
        
        auto cmp = [](pair<long long, int>& a, pair<long long, int>& b) {
            return a.first > b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, decltype(cmp)> heap(cmp);
        
        for (int i = 0; i < n; i++) {
            heap.push({static_cast<long long>(nums[i]), i});
        }
        
        unordered_map<int, int> counts;
        
        while (counts.size() < n && k > 0) {
            auto [x, y] = heap.top();
            heap.pop();
            x *= multiplier;
            
            heap.push({x, y});
            counts[y]++;
            k--;
        }

        long long exp = k / n;
        int rem = k % n;

        vector<int> res(n, 0);
        while (!heap.empty()) {
            auto [num, pos] = heap.top();
            heap.pop();
            
            long long mul = powerMod(multiplier, exp + (rem > 0 ? 1 : 0));
            res[pos] = static_cast<int>((num % MOD * mul % MOD) % MOD);
            rem--;
        }

        return res;
    }
};