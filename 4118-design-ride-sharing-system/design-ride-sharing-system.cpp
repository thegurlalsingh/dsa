class RideSharingSystem {
public:
    map<int, int> riderToTime;
    map<int, int> timeToRider;
    map<int, int> timeToDriver;

    int timeAdd = 0;

    RideSharingSystem() {
    }
    
    void addRider(int riderId) {
        riderToTime[riderId] = timeAdd;
        timeToRider[timeAdd] = riderId;
        timeAdd++;
    }
    
    void addDriver(int driverId) {
        timeToDriver[timeAdd] = driverId;
        timeAdd++;
    }
    
    vector<int> matchDriverWithRider() {
        if(timeToDriver.empty() || timeToRider.empty()){
            return {-1, -1};
        }
        auto itDriver = timeToDriver.begin(); auto itRider = timeToRider.begin();
        int driver = itDriver->second; int rider = itRider->second; int timeRider = itRider->first; int timeDriver = itDriver->first;
        timeToDriver.erase(timeDriver); timeToRider.erase(timeRider); riderToTime.erase(rider);
        return {driver, rider};
    }
    
    void cancelRider(int riderId) {
        if(riderToTime.find(riderId) != riderToTime.end()){
            int time = riderToTime[riderId];
            riderToTime.erase(riderId);
            timeToRider.erase(time);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */