class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *sentinal=new ListNode(), *cur=sentinal;

        while (head!=NULL)
        {
            ListNode *next=head;
            while (next!=NULL&&next->val==val)
                next=next->next;

            if (head==next)
            {
                next=head->next;
                cur->next=head;
                cur=cur->next;
                cur->next=NULL;
            }
            head=next;
        }
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};