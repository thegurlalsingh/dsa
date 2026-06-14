class Trie{
    struct Node{
        Node* links[2];
        Node(){
            links[0] = links[1] = nullptr;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(int num){
        Node* node = root;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            if(!node->links[bit]){
                node->links[bit] = new Node();
            }
            node = node->links[bit];
        }
    }

    int maxXor(int num){
        Node* node = root;
        int ans = 0;
        for(int i = 31; i >= 0; i--){
            int bit = (num >> i) & 1;
            int opp = 1 - bit;

            if(node -> links[opp]){
                ans |= (1 << i);
                node = node->links[opp];
            }
            else{
                node = node->links[bit];
            }
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries) {
        sort(nums.begin(), nums.end());
        vector<int> ans(queries.size(), 0);
        vector<vector<int>> v;
        for(int i = 0; i < queries.size(); i++){
            v.push_back({queries[i][1], queries[i][0], i});
        }
        sort(v.begin(), v.end());
        Trie t;
        int idx = 0;
        for(int i = 0; i < v.size(); i++){
            int mi = v[i][0]; int xi = v[i][1]; int qi = v[i][2];
            while(idx < nums.size() && nums[idx] <= mi){
                t.insert(nums[idx]);
                idx++;
            }
            if(idx == 0){
                ans[qi] = -1;
            }
            else{
                ans[qi] = t.maxXor(xi);
            }
        }
        return ans;
    }
};