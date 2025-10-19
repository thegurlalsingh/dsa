typedef long long ll;
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<ll, ll> sixty;
        
        // Step 1: Count remainders
        for(int i = 0; i < time.size(); i++){
            ll m = time[i] % 60;
            sixty[m]++;
            time[i] = m;  // keep your in-place modification
        }

        ll count = 0;
        // Step 2: Count pairs
        for(int i = 0; i < time.size(); i++){
            ll rem = time[i];
            ll complement = (rem == 0) ? 0 : 60 - rem;
            count += sixty[complement];

            // If rem + rem = 60, we counted itself, so subtract
            if (complement == rem) count--;
        }

        return count / 2;  // divide by 2 to fix double counting
    }
};
