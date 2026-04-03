class Solution {
public:
        int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
            int totalTank = 0, tank = 0, start = 0;
            int n = gas.size();
            
            for(int i = 0; i < n; i++) {
                int net = gas[i] - cost[i];
                totalTank += net;
                tank += net;
                if(tank < 0) {
                    start = i + 1;
                    tank = 0;
                }
            }
            return totalTank >= 0 ? start : -1;
        }
};