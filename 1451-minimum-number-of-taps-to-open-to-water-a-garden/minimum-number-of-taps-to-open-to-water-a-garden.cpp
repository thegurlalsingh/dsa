class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>> v;
        for(int i=0;i<=n;i++){
            int L = max(0, i - ranges[i]);
            int R = min(n, i + ranges[i]);
            v.push_back({L, R});
        }
        
        sort(v.begin(), v.end());
        
        int taps = 0;
        int i = 0, current_end = 0, farthest = 0;
        
        while(current_end < n){
            bool expanded = false;
            
            while(i <= n && v[i].first <= current_end){
                farthest = max(farthest, v[i].second);
                i++;
                expanded = true;
            }

            if(!expanded) return -1; // stuck = no coverage
            
            taps++;
            current_end = farthest;
        }

        return taps;
    }
};
