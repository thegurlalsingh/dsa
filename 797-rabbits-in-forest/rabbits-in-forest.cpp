class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for (int a : answers) {
            freq[a]++;
        }
        
        int count = 0;
        for (auto& [x, f] : freq) {
            int groupSize = x + 1;
            int groups = (f + groupSize - 1) / groupSize; 
            count += groups * groupSize;
        }
        return count;
    }
};
