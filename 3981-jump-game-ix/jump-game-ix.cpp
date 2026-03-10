class DSU{
    private:
    vector<int> parent, rank;
    
    public : 
    DSU(int n){
        parent.resize(n);
        rank.resize(n, 0);
        for(int i = 0; i < n; i++){
            parent[i] = i;
        }
    }
    
    int find(int x){
        if(parent[x] == x) return x;
        
        return parent[x] = find(parent[x]);
    }
    
    void unite(int x , int y){
        int px = find(x);
        int py = find(y);
        
        if(px == py) return;
        
        if(rank[px] > rank[py]){
            parent[py] = px;
        }else if(rank[py] > rank[px]){
            parent[px] = py;
        }else{
                parent[px] = py;
                rank[py]++;
        }
    }
    
    bool isConnected(int x, int y){
        return find(x) == find(y);
    }
};


class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        DSU d(n);

        stack<int> st;
        for(int i = 0; i < n; i++){
            int x = i;
            while(!st.empty() && nums[st.top()] > nums[i]){
                if(nums[st.top()] > nums[x]) x = st.top();
                d.unite(st.top(), i);
                st.pop();
            }
            d.unite(x, i);
            st.push(x);
        }

        vector<int> maxi(n, 0);
        for(int i = 0; i < n; i++){
            int p = d.find(i);
            maxi[p] = max(maxi[p], nums[i]);
        }

        vector<int> ans(n);
        for(int i = 0; i < n; i++){
            ans[i] = maxi[d.find(i)];
        }
        return ans;
    }
};