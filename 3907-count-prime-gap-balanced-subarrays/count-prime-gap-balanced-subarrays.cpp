class SegTreeMax {
public:
    int n;
    vector<int> seg;

    SegTreeMax(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int idx, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid, arr);
        build(2 * idx + 2, mid + 1, r, arr);
        seg[idx] = max(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MIN; // no overlap
        if (ql <= l && r <= qr) return seg[idx]; // complete overlap

        int mid = (l + r) / 2;
        return max(
            query(2 * idx + 1, l, mid, ql, qr),
            query(2 * idx + 2, mid + 1, r, ql, qr)
        );
    }
};
class SegTreeMin {
public:
    int n;
    vector<int> seg;

    SegTreeMin(vector<int>& arr) {
        n = arr.size();
        seg.resize(4 * n);
        build(0, 0, n - 1, arr);
    }

    void build(int idx, int l, int r, vector<int>& arr) {
        if (l == r) {
            seg[idx] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(2 * idx + 1, l, mid, arr);
        build(2 * idx + 2, mid + 1, r, arr);
        seg[idx] = min(seg[2 * idx + 1], seg[2 * idx + 2]);
    }

    int query(int idx, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return INT_MAX; // no overlap
        if (ql <= l && r <= qr) return seg[idx]; // complete overlap

        int mid = (l + r) / 2;
        return min(
            query(2 * idx + 1, l, mid, ql, qr),
            query(2 * idx + 2, mid + 1, r, ql, qr)
        );
    }
};

class Solution {
    vector<bool> sieve(int n) {
        vector<bool> isPrime(n + 1, true);
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        return isPrime;
    }

public:
    int primeSubarray(vector<int>& nums, int k) {
        int n = nums.size(); 
        vector<bool> isPrime = sieve(1e5);

        vector<int> minArr(n), maxArr(n);
        for (int i = 0; i < n; i++) {
            if (isPrime[nums[i]]) {
                minArr[i] = nums[i];
                maxArr[i] = nums[i];
            } else {
                minArr[i] = INT_MAX;
                maxArr[i] = INT_MIN;
            }
        }

        SegTreeMin smin(minArr);
        SegTreeMax smax(maxArr);

        int i = 0, j = 0;
        int ans = 0;

        vector<int> primeIdx;

        while (j < n) {
            if (isPrime[nums[j]]) {
                primeIdx.push_back(j);
            }
            while (i <= j) {
                if (primeIdx.size() < 2) break;
                int mini = smin.query(0, 0, n - 1, i, j);
                int maxi = smax.query(0, 0, n - 1, i, j);
                if ((maxi - mini) <= k) {
                    break;
                }
                if (isPrime[nums[i]]) {
                    primeIdx.erase(primeIdx.begin());
                }
                i++;
            }
            if (primeIdx.size() >= 2) {
                int secondLast = primeIdx[primeIdx.size() - 2];
                ans += (secondLast - i + 1);
            }
            j++;
        }

        return ans;
    }
};