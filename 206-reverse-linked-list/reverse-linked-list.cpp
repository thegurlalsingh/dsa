class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;

        while (curr) {
            next = curr->next;   // store next
            curr->next = prev;   // reverse current node
            prev = curr;         // move prev forward
            curr = next;         // move curr forward
        }

        return prev; // new head
    }
};
