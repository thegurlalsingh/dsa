class Solution {
    struct Compare {
    bool operator()(pair<int, int> const& p1, pair<int, int> const& p2) {
            return p1.second > p2.second; 
        }
};
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<int> result;
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(make_pair(i,nums[i]));
            if(pq.size()>k){
                pq.pop();
            }
        }
        vector<pair<int, int>> temp;
        while (!pq.empty()) {
            temp.push_back(pq.top());
            pq.pop();
        }
        sort(temp.begin(), temp.end(), [](pair<int, int>& a, pair<int, int>& b) {
            return a.first < b.first;
        });
        
        for (auto& p : temp) {
            result.push_back(p.second);
        }
        
        return result;
    }
};