class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            auto A = points[i];
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                auto B = points[j];

                if (A[0] <= B[0] && A[1] >= B[1]) {
                    bool valid = true;

                    for (int k = 0; k < n; k++) {
                        if (k == i || k == j) {
                            continue;
                        }
                        auto C = points[k];

                        if (C[0] >= A[0] && C[0] <= B[0] &&
                            C[1] <= A[1] && C[1] >= B[1]) {
                            valid = false;
                            break;
                        }
                    }
                    if (valid) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
