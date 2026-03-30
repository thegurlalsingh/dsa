class Solution {
    bool check(int maxi, vector<int>& quantities, int n){
        int stores = 0;

        for(int i = 0; i < quantities.size(); i++){
            stores += (quantities[i] + maxi - 1) / maxi; 
        }

        return stores <= n;
    }

public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low = 1, high = 1e9;
        int ans = -1;

        while(low <= high){
            int mid = (low + high) / 2;

            if(check(mid, quantities, n)){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};