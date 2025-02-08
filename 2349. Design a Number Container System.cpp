class NumberContainers {
public:
    unordered_map<long, priority_queue<long, vector<long>, greater<long>>> mp;  // number -> min-heap of indices
    unordered_map<long, long> ind; 

    NumberContainers() {}
    
    void change(int index, int number) {
        ind[index] = number;  
        mp[number].push(index); 
    }
    
    int find(int number) {
        while (!mp[number].empty()) {
            int minIndex = mp[number].top();  
            if (ind[minIndex] == number) {
                return minIndex;
            }
            mp[number].pop();
        }
        return -1; 
    }
};