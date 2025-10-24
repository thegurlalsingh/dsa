class Solution {
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        while (curr) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* t1 = l1;
        ListNode* t2 = l2;

        ListNode* res = new ListNode(-1);
        ListNode* tail = res;
        int carry = 0;

        while (t1 || t2 || carry) {
            int x = (t1 ? t1->val : 0);
            int y = (t2 ? t2->val : 0);

            int sum = x + y + carry;
            carry = sum / 10;
            int digit = sum % 10;

            tail->next = new ListNode(digit);
            tail = tail->next;

            if (t1) t1 = t1->next;
            if (t2) t2 = t2->next;
        }

        // reverse again before returning
        return res->next;
    }
};
