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
        stack<int> st;
        ListNode* curr = h;
        while (curr) {
            st.push(curr->val);
            curr = curr->next;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        while (!st.empty()) {
            ListNode* node = new ListNode(st.top());
            st.pop();
            prev->next = node;
            prev = prev->next;
        }
        return dummy->next;

    }
    int size(ListNode* h){
        ListNode* temp = h;
        int count = 0;
        while(temp){
            temp = temp->next;
            count++;
        }
        return count;
    }
public:
    void reorderList(ListNode* head) {
        ListNode* rev = reverse(head);
        int sz = size(head);
        int valueofmiddle = 0;
        if(sz % 2 == 1){ // odd size of linked list -> middle node would be left
            int middle = floor(sz / 2);
            ListNode* d = head;
            while(middle--){
                d = d->next;
            }
            valueofmiddle = d->val;
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* prev = dummy;
        ListNode* l1 = head;
        ListNode* l2 = rev;
        int half = floor(sz / 2);
        while(half--){
            ListNode* n1 = nullptr;
            ListNode* n2 = nullptr;
            if(l1->next){
                n1 = l1->next;
            }
            if(l2->next){
                n2 = l2->next;
            }
            
            l1->next = l2;
            l2->next = nullptr;
            prev->next = l1;
            prev = prev->next->next;
            l1 = n1;
            l2 = n2;
        }
        if(sz % 2 == 1){ // odd size of linked list -> middle node would be left
            ListNode* k = dummy;
            ListNode* temp = new ListNode(valueofmiddle);
            while(k->next){
                k = k->next;
            }
            k->next = temp;
        }
        head = dummy->next;
    }
};