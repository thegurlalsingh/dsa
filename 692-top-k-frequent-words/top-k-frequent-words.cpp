class Solution {
    struct cmp {
    bool operator()(const pair<int,string>& a, const pair<int,string>& b) {
        if(a.first == b.first){
            return a.second > b.second;
        }
        return a.first < b.first;
    }
};

public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;
        unordered_map<string, int> mp;
        for(int i = 0; i < words.size(); i++){
            mp[words[i]]++;
        }
        for(auto& p : mp){
            pq.push({p.second, p.first});
        }
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        // sort(ans.begin(), ans.end());
        return ans;
    }
};