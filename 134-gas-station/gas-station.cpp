class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = 0;
        int rem = 0;
        int total = 0;

        for (int i = 0; i < gas.size(); i++) {
            rem += gas[i] - cost[i];
            total += gas[i] - cost[i];
            if (rem < 0) {
                index = i + 1;
                rem = 0;
            }
        }

        if (total < 0){
            return -1;
        }
        return index;
    }
};