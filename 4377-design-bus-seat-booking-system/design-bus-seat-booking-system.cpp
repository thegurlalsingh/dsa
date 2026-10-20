class BusBooking {
    vector<vector<int>> seats;
    unordered_map<char, int> mp;
    int totalTime = 0;
    int minTime = 0;
    map<pair<int, int>, int> cost;
public:
    BusBooking(int n) {
        seats.resize(n, vector<int>(4, -1));
        mp['A'] = 0; mp['B'] = 1; mp['C'] = 2; mp['D'] = 3;
    }
    
    void toggle(string seat) {
        int r = stoi(seat.substr(1)) - 1;
        int c = mp[seat[0]]; 

        if(seats[r][c] == -1){
            if(c == 0){
                if(seats[r][c + 1] == 1){
                    totalTime += 3;
                    cost[{r, c}] = 3;
                }
                else{
                    totalTime += 1;
                    cost[{r, c}] = 1;
                }
            } 
            else if(c == 3){
                if(seats[r][c - 1] == 1){
                    totalTime += 3;
                    cost[{r, c}] = 3;
                }
                else{
                    totalTime += 1;
                    cost[{r, c}] = 1;
                }
            }
            else{
                totalTime += 1;
                cost[{r, c}] = 1;
            }
            minTime++;
            seats[r][c] = 1;
        }

        else{
            totalTime -= cost[{r, c}];
            minTime--;
            seats[r][c] = -1;
        }
    }
    
    int getTotalTime() {
        return totalTime;
    }
    
    int getMinTime() {
        return minTime;
    }
};

/**
 * Your BusBooking object will be instantiated and called as such:
 * BusBooking* obj = new BusBooking(n);
 * obj->toggle(seat);
 * int param_2 = obj->getTotalTime();
 * int param_3 = obj->getMinTime();
 */