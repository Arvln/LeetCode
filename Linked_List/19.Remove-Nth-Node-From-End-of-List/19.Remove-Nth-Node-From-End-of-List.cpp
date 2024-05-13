class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *sentinal=new ListNode(), *f=head, *s=sentinal;
        sentinal->next=head;
        while (n>0)
        {
            f=f->next;
            n--;
        }
        while (f!=NULL)
        {
            f=f->next;
            s=s->next;
        }
        s->next=s->next->next;

        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};