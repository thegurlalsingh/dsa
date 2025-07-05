class RandomizedCollection {
public:
    map<int, set<int>> m;
    vector<int> v;

    RandomizedCollection() {}

    bool insert(int val) {
        v.push_back(val);
        m[val].insert(v.size() - 1);
        return m[val].size() == 1;
    }

    bool remove(int val) {
        auto it = m.find(val);
        if (it != m.end()) {
            auto pos = *it->second.begin();
            it->second.erase(it->second.begin());
            v[pos] = v.back();
            m[v.back()].insert(pos);
            m[v.back()].erase(v.size() - 1);
            v.pop_back();
            if (it->second.empty())
                m.erase(it);
            return true;
        }
        return false;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};
