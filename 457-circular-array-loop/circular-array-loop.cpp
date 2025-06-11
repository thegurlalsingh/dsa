class Solution {
private:
    int nextIndex(vector<int>& nums, int i) {
        int n = nums.size();
        int next = (i + nums[i]) % n;
        if (next < 0) {
            next += n;
        }
        return next;
    }

    bool isCycle(vector<int>& nums, int start) {
        int n = nums.size();
        bool forward = nums[start] > 0;
        int current = start;

        unordered_set<int> visited;

        while (true) {
            int next = nextIndex(nums, current);

            if ((nums[next] > 0) != forward) {
                return false;
            }

            if (next == current) {
                return false;
            }

            if (visited.count(next)) {
                return true;
            }

            visited.insert(current);
            current = next;
        }
        return false;
    }
public:
    bool circularArrayLoop(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (isCycle(nums, i)) {
                return true;
            }
        }
        return false;
    }
};