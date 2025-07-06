class FindSumPairs {
    unordered_map<int, int> m1;
    unordered_map<int, int> m2;
    unordered_map<int, int> freq;  
    vector<int> nums1, nums2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;

        for (int i = 0; i < nums1.size(); i++) {
            m1[i] = nums1[i];
        }

        for (int i = 0; i < nums2.size(); i++) {
            m2[i] = nums2[i];
            freq[nums2[i]]++;
        }
    }

    void add(int index, int val) {
        int oldVal = m2[index];
        int newVal = oldVal + val;
        m2[index] = newVal;
        nums2[index] = newVal;

        freq[oldVal]--;
        if (freq[oldVal] == 0) {
            freq.erase(oldVal);
        }
        freq[newVal]++;
    }

    int count(int tot) {
        int c = 0;
        for (auto& p : m1) {
            int val1 = p.second;
            int rem = tot - val1;
            if (freq.count(rem)) {
                c += freq[rem];
            }
        }
        return c;
    }
};
