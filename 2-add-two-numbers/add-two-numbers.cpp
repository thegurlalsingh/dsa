class Solution {
public:

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;
        ListNode* first = l1;
        ListNode* second = l2;
        int carry = 0;
        while(first || second || carry) { //didnt focus on this carry part as while condition
            int sum = carry;
            if(first) {
                sum += first->val; // missed some conditions of checking
                first = first->next;
            }
            if(second) {
                sum += second->val;
                second = second->next;
            }
            carry = sum / 10;
            ListNode* temp = new ListNode(sum % 10);
            curr->next = temp;
            curr = curr->next;
        }
        return dummy->next;
    }
};