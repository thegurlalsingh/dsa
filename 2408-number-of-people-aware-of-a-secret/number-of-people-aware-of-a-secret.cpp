class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9+7;
        queue<pair<long long, int>> q; 
        q.push({1, 1}); 

        for(int day = 1; day <= n; day++){
            int size = q.size();
            long long newSharers = 0;

            for(int i = 0; i < size; i++){
                auto [cnt, startDay] = q.front(); q.pop();
                int daysPassed = day - startDay;

                if(daysPassed >= delay && daysPassed < forget){
                    newSharers = (newSharers + cnt) % MOD;
                }

                if(daysPassed < forget){
                    q.push({cnt, startDay});
                }
            }

            if(newSharers > 0){
                q.push({newSharers, day});
            }
        }

        long long result = 0;
        while(!q.empty()){
            result = (result + q.front().first) % MOD;
            q.pop();
        }

        return (int)result;
    }
};
