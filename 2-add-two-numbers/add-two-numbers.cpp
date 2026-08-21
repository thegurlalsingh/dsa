/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverse(ListNode* h){
        ListNode* prev = nullptr;
        ListNode* curr = h;

        while(curr){
            ListNode* n = curr->next;
            curr->next = prev;
            prev = curr;
            curr = n;
        }

        return prev;

    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* revl1 = l1;
        ListNode* revl2 = l2;
        ListNode* dummy = new ListNode(-1);
        ListNode* curr1 = revl1;
        ListNode* curr2 = revl2;
        ListNode* curr3 = dummy;
        int carry = 0;

        while(curr1 || curr2 || carry){
            int t = carry;
            if (curr1) {
                t += curr1->val;
            }
            if (curr2) {
                t += curr2->val;
            }
            int add = t % 10; int rem = t / 10;
            ListNode* n = new ListNode(add);
            carry = rem;
            curr3->next = n;
            curr3 = curr3->next;
            if(curr1){
                curr1 = curr1->next;
            }
            if(curr2){
                curr2 = curr2->next;
            }
        }

        return dummy->next;
    }
};