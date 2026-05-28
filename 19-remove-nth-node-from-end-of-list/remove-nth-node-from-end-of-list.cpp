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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr){
            return nullptr;
        }
        
        int count = 0;
        ListNode* temp = head;
        while(temp){
            count++;
            temp = temp->next;
        }
        if(count == n) {
            return head->next;
        }
        int prev = count - n - 1;
        temp = head;
        while(prev--){
            temp = temp->next;
        }
        ListNode* nex = nullptr;
        if(temp->next->next){
            nex = temp->next->next;
        }
        temp->next = nex;
        return head;
    }
};