class Solution {
private:
    bool check(vector<int>& a) {
        return (2 * (a[0] + a[2])) == a[1];
    }

public:
    int countSubarrays(vector<int>& nums) {
        int i = 0;
        int j = 0;
        int n = nums.size();
        vector<int> a;
        int count = 0;
        while(j < n){
            a.push_back(nums[j]);
            if(a.size() == 3){
                if(check(a)){
                    count++;
                }
                a.erase(a.begin());
                i++;
            }
            j++;
        }
        return count;
    }
};