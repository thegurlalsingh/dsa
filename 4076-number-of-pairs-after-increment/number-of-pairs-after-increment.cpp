class SqrtDecomposition {
    int n;
    int blockSize;
    vector<long long> arr;
    vector<int> nums1;
    vector<long long> blockSum;
    vector<unordered_map<long long, int>> freq;
    vector<long long> lazy;

public:
    SqrtDecomposition(vector<long long>& nums, vector<int>& t) {
        arr = nums;
        nums1 = t;
        n = arr.size();
        blockSize = 700;
        int numBlocks = (n + blockSize - 1) / blockSize;
        blockSum.resize(numBlocks, 0);
        freq.resize(numBlocks, unordered_map<long long, int>());
        lazy.resize(numBlocks, 0);
        for (int i = 0; i < n; i++) {
            blockSum[i / blockSize] += arr[i];
            freq[i / blockSize][arr[i]] += 1;
        }
    }

    void update(int l, int r, int value){
        while(l <= r && l % blockSize != 0){
            freq[l / blockSize][arr[l]]--;
            arr[l] += value;
            freq[l / blockSize][arr[l]]++;
            l++;
        }
        while(l + blockSize - 1 <= r){
            lazy[l / blockSize] += value;
            l += blockSize;
        }
        while(l <= r){
            freq[l / blockSize][arr[l]]--;
            arr[l] += value;
            freq[l / blockSize][arr[l]]++;
            l++;
        }
    }

    int query(int val){
        int numBlocks = (n + blockSize - 1) / blockSize;
        int ans = 0;
        for(int i = 0; i < nums1.size(); i++){
            for(int j = 0; j < numBlocks; j++){
                // value in nums2 = val - (nums1[i] + lazy[j]) -> this nums[i] + lazy[j] is new value in nums2 after update
                if(freq[j].find(val - (nums1[i] + lazy[j])) != freq[j].end()){
                    ans += freq[j][val - (nums1[i] + lazy[j])];
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        vector<long long> nnums2;
        for(int i = 0; i < nums2.size(); i++){
            nnums2.push_back((long long)nums2[i]);
        }
        SqrtDecomposition sd(nnums2, nums1);
        vector<int> ans;
        for(int i = 0; i < queries.size(); i++){
            if(queries[i][0] == 1){
                sd.update(queries[i][1], queries[i][2], queries[i][3]);
            }
            else{
                ans.push_back(sd.query(queries[i][1]));
            }
        }
        return ans;
    }
};