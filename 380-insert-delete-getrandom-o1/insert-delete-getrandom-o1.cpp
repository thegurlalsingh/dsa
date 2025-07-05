class RandomizedSet {
public:
    unordered_set<int> set;
    vector<int> v;

    RandomizedSet() {
    }

    bool insert(int val) {
        if (set.find(val) == set.end()) {
            set.insert(val);
            v.push_back(val);
            return true;
        }
        return false;
    }

    bool remove(int val) {
        if (set.find(val) != set.end()) {
            set.erase(val);
            auto it = find(v.begin(), v.end(), val);
            v.erase(it);  
            return true;
        }
        return false;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */