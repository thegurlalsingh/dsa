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
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right || head == nullptr) {
            return head;
        }
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        ListNode* curr = prev->next;
        ListNode* forward = nullptr;
        ListNode* nextOfRight = nullptr;

        ListNode* prevRev = nullptr;
        for (int i = left; i <= right; i++) {
            forward = curr->next;
            curr->next = prevRev;
            prevRev = curr;
            curr = forward;
        }
        
        prev->next->next = forward;  
        prev->next = prevRev;        

        return dummy->next; 
    }
};
