class Solution {
public:
    long long maxPoints(vector<int>& technique1, vector<int>& technique2, int k) {
        int n = (int)technique1.size();
        vector<int> gain;
        long long sum = 0;

        for (int i = 0; i < n; i++) {
            sum += technique2[i];
            gain.push_back(technique1[i] - technique2[i]);
        }

        sort(gain.rbegin(), gain.rend());

        for (int i = 0; i < k; i++)
            sum += gain[i];

        for (int i = k; i < n; i++) {
            if (gain[i] > 0)
                sum += gain[i];
        }

        return sum;
    }
};