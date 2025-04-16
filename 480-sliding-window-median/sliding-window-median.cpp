#include <iostream>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <queue>
#include <unordered_map>

using namespace std;
using namespace __gnu_pbds;

typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

struct SortedQueue {
    ordered_set data;                   
    queue<int> insert_order;             
    unordered_map<int, int> id_to_val;   
    int current_id = 0;

    void push(int val) {
        data.insert({val, current_id});
        insert_order.push(current_id);
        id_to_val[current_id] = val;
        current_id++;
    }

    void pop() {
        if (!insert_order.empty()) {
            int id = insert_order.front();
            insert_order.pop();
            int val = id_to_val[id];
            data.erase({val, id});
            id_to_val.erase(id);
        }
    }

    int at(int index) const {
        if (index < 0 || index >= size()) throw out_of_range("Index out of range");
        return data.find_by_order(index)->first;
    }

    int front_sorted() const {
        if (empty()) throw out_of_range("Queue is empty");
        return data.begin()->first;
    }

    int back_sorted() const {
        if (empty()) throw out_of_range("Queue is empty");
        return data.rbegin()->first;
    }

    int size() const {
        return data.size();
    }

    bool empty() const {
        return data.empty();
    }
};


class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        SortedQueue sd;
        vector<double> result;

        for (int i = 0; i < nums.size(); i++) {
            sd.push(nums[i]);

            if (sd.size() > k) {
                sd.pop();  
            }

            if (sd.size() == k) {
                if (k % 2 != 0) {
                    result.push_back(sd.at(k / 2));
                } else {
                    double val1 = sd.at(k / 2);
                    double val2 = sd.at(k / 2 - 1);
                    result.push_back((val1 + val2) / 2.0);
                }
            }
        }

        return result;
    }
};