class RecentCounter {
    deque<int> dq;
    
public:
    RecentCounter() {
        
    }
    
    int ping(int t) {
        while(!dq.empty() && (dq.front() < t - 3000 || dq.front() > t)){
            dq.pop_front();
        }
        dq.push_back(t);
        return dq.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */