class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long count = 0; priority_queue<pair<int, int>> pq;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                pq.push({nums[i], i});
            }
            else{
                if(!pq.empty() && nums[i] < pq.top().first && pq.top().second < i){
                    swap(s[i], s[pq.top().second]);
                    pq.pop();
                    pq.push({nums[i], i});
                }
            }
        }
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                count += (long long)nums[i];
            }
        }

        return count;
    }
};