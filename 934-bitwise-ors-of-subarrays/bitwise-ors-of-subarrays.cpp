class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> res;
        unordered_set<int> cur;
        
        for (int x : arr) {
            unordered_set<int> new_cur = {x};
            for (int val : cur) {
                new_cur.insert(val | x);
            }
            cur = new_cur;
            res.insert(cur.begin(), cur.end());
        }
        
        return res.size();
    }
};
