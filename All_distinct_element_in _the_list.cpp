class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode dummy(-101);
        dummy.next = head;

        ListNode* prev = &dummy;
        ListNode* temp = prev->next;

        while(temp != nullptr){
            ListNode* front = temp->next;
            if(temp->val == prev->val){
                prev->next = front;
                ListNode* del = temp;
                temp = front;
                delete(del);
            }
            else{
                prev = temp;
                temp = front;
            }
        }

        return dummy.next;
    }
};
