class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *sentinal=new ListNode();
        while (head!=NULL)
        {
            ListNode *next=head->next;
            head->next=sentinal->next;
            sentinal->next=head;
            head=next;
        }
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};