using ll = long long;

struct Node {
    ll value;
    int index;
    int prev;
    int next;

    Node(ll v, int i, int n) : value(v), index(i) {
        prev = i - 1;
        next = i + 1 < n ? i + 1 : -1;
    }
};

struct Pair {
    ll sum;
    int index; 

    bool operator<(const Pair& other) const {
        return tie(sum, index) < tie(other.sum, other.index);
    }
};

class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        vector<Node> nodes;
        for (int i = 0; i < n; i++) {
            nodes.emplace_back(nums[i], i, n);
        }

        set<Pair> s;
        int cnt = 0;

        for (int i = 0; i < n - 1; i++) {
            if (nodes[i].value > nodes[i + 1].value) {
                cnt++;
            }
            s.insert({nodes[i].value + nodes[i + 1].value, i});
        }

        int ans = 0;

        while (cnt > 0) {
            int i = s.begin()->index;
            int j = nodes[i].next;
            int p = nodes[i].prev;
            int q = nodes[j].next;

            if (nodes[i].value > nodes[j].value) {
                cnt--;
            }

            if (p >= 0) {
                if (nodes[p].value > nodes[i].value && nodes[p].value <= nodes[i].value + nodes[j].value) {
                    cnt--;
                }
                else if (nodes[p].value <= nodes[i].value && nodes[p].value > nodes[i].value + nodes[j].value) {
                    cnt++;
                }
            }

            if (q != -1) {
                if (nodes[q].value >= nodes[j].value && nodes[q].value < nodes[i].value + nodes[j].value) {
                    cnt++;
                }
                else if (nodes[q].value < nodes[j].value && nodes[q].value >= nodes[i].value + nodes[j].value) {
                    cnt--;
                }
            }

            s.erase({nodes[i].value + nodes[j].value, i});
            if (p >= 0) {
                s.erase({nodes[p].value + nodes[i].value, p});
            }
            if (q != -1) {
                s.erase({nodes[j].value + nodes[q].value, j});
            }

            nodes[i].value += nodes[j].value;
            nodes[i].next = q;
            if (q != -1) {
                nodes[q].prev = i;
            }

            if (p >= 0) {
                s.insert({nodes[p].value + nodes[i].value, p});
            }
            if (q != -1) {
                s.insert({nodes[i].value + nodes[q].value, i});
            }

            ans++;
        }

        return ans;
    }
};
