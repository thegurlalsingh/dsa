class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> cooldown;
        priority_queue<pair<int, char>> freq;

        unordered_map<char, int> mp;
        for (char c : tasks) {
            mp[c]++;
        }
        for (auto& [c, f] : mp) {
            freq.push({f, c});
        }
        
        int time = 0;
        int count = tasks.size();
        while (count > 0) {
            // while (!pq.empty() && mp[pq.top().second] == 0) {
            //     pq.pop();
            // }
            while(!cooldown.empty() && cooldown.top().first == time) {
                auto [availableTime, c] = cooldown.top(); cooldown.pop();
                if (mp[c] > 0) {
                    freq.push({mp[c], c});
                }
            }
            if(!freq.empty()){
                auto [f, c] = freq.top(); freq.pop();
                mp[c]--;
                count--;
                cooldown.push({time + n + 1, c});
                
            }
            time++;
        }

        return time;
    }
};