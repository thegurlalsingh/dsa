class Solution {
public:
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min-heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Push all non-null heads
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;

        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            tail->next = top;
            tail = tail->next;

            if (top->next) {
                pq.push(top->next);
            }
        }

        return dummy->next;
    }
};
