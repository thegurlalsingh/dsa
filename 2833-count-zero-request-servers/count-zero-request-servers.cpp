class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        vector<pair<int, int>> q;
        for(int i = 0; i < queries.size(); i++){
            q.push_back({queries[i], i});
        }
        sort(q.begin(), q.end());

        vector<int> ans(q.size(), 0);
        int unique = 0;
        unordered_map<int, int> mp;
        int start = 0;
        int end = 0;


        for(int i = 0; i < q.size(); i++){
            int s = q[i].first - x;
            int e = q[i].first;

            while(end < logs.size() && logs[end][1] <= e){
                if(mp[logs[end][0]] == 0){
                    unique++;
                } 
                mp[logs[end][0]]++;
                
                end++;
            }

            while(start < end && logs[start][1] < s){
                if(mp.find(logs[start][0]) != mp.end()){
                    mp[logs[start][0]]--;
                    if(mp[logs[start][0]] == 0){
                        unique--;
                    }
                }
                start++;
            }

            ans[q[i].second] = n - unique;
        }

        return ans;
    }
};