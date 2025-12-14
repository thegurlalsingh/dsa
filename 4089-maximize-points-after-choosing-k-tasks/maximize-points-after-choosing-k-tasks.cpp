class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = technique1.size();
        vector<pair<int,int>> diff(n, {-1, -1});
        vector<int> visited(n, -1);
        for(int i = 0; i < n; i++){
            diff[i] = {(technique1[i] - technique2[i]), i};
        }
        sort(diff.begin(), diff.end(), greater<>());
        int i = 0; long long sum = 0;
        while(k--){
            int idx = diff[i].second;
            visited[idx] = 1;
            sum += technique1[idx];
            i++;
        }
        for(int i = 0; i < n; i++){
            if (visited[i] == -1){
                sum += max(technique1[i], technique2[i]);
            }
        }
        return sum;
    }
};