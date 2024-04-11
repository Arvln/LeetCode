class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *sentinal=new ListNode(-101), *cur=sentinal;
        while (head!=NULL)
        {
            ListNode *next=head->next;
            head->next=NULL;
            if (head->val!=cur->val)
            {
                cur->next=head;
                cur=cur->next;
            }
            head=next;
        }
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};