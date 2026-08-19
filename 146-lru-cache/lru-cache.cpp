class LRUCache {
    list<pair<int, int>> l;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        int val;
        if(mp.find(key) == mp.end()){
            return -1;
        }
        val = mp[key]->second;
        l.erase(mp[key]);
        mp.erase(key);
        l.push_front({key, val});
        mp[key] = l.begin();
        return val;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            l.erase(mp[key]);
            mp.erase(key);
        }
        while(l.size() >= capacity){
            int key = l.back().first;
            l.pop_back();
            mp.erase(key);
        }
        l.push_front({key, value});
        mp[key] = l.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */