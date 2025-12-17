typedef pair<int, int> P;

class Solution {

    struct cmp {
        bool operator()(const P& a, const P& b) const {
            if (a.first != b.first)
                return a.first > b.first;   // min distance
            return a.second < b.second;     // max balance
        }
    };

public:
    long long minMoves(vector<int>& balance) {
        long long ans = 0;
        long long total = accumulate(balance.begin(), balance.end(), 0LL);
        if (total < 0) return -1;

        int neg = -1;
        for(int i = 0; i < balance.size(); i++){
            if(balance[i] < 0){
                neg = i;
                break;
            }
        }

        if(neg == -1) return 0;

        int n = balance.size();
        priority_queue<P, vector<P>, cmp> pq;

        for(int i = 0; i < n; i++){
            if(i == neg || balance[i] <= 0) continue;

            int d = abs(neg - i);
            int dist = min(d, n - d);
            pq.push({dist, balance[i]});
        }

        while(balance[neg] < 0 && !pq.empty()){
            auto [dist, supply] = pq.top();
            pq.pop();

            int take = min(supply, -balance[neg]);
            ans += 1LL * take * dist;
            balance[neg] += take;
            supply -= take;

            if(supply > 0){
                pq.push({dist, supply});
            }
        }

        return balance[neg] == 0 ? ans : -1;
    }
};
