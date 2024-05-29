class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *f=head, *s=head;
        while (f!=NULL&&f->next!=NULL)
        {
            f=f->next->next;
            s=s->next;

            if (f==s) break;
        }

        if (f==NULL||f->next==NULL) return NULL;

        s=head;
        while (f!=s)
        {
            f=f->next;
            s=s->next;
        }
        return s;
    }
};