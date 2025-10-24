class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        ListNode* res = new ListNode(-1);
        ListNode* tail = res;

        while(temp1 && temp2){  // fix condition
            if(temp1->val > temp2->val){
                tail->next = new ListNode(temp2->val);
                temp2 = temp2->next;
            }
            else{
                tail->next = new ListNode(temp1->val);
                temp1 = temp1->next;
            }
            tail = tail->next;
        }

        // handle leftovers
        while(temp1){
            tail->next = new ListNode(temp1->val);
            temp1 = temp1->next;
            tail = tail->next;
        }

        while(temp2){
            tail->next = new ListNode(temp2->val);
            temp2 = temp2->next;
            tail = tail->next;
        }

        return res->next;
    }
};
