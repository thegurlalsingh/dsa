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
    int size(ListNode* head){
        int t = 0;
        ListNode* curr = head;
        while(curr){
            t++;
            curr = curr->next;
        }
        return t;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int sz = size(head);
        if(sz == 1){
            return nullptr;
        }
        ListNode* curr = head;
        if(sz - n == 0){
            return head->next;
        }
        int r = sz - n - 1;
        
        while(curr && r--){
            curr = curr->next;
        }

        ListNode* ne = curr->next->next;
        curr->next = ne;
        return head;
    }
};