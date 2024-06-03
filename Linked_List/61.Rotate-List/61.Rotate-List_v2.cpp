class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *sentinal=new ListNode (0, head), *last=sentinal;
        int len=0;
        while (last->next!=NULL)
        {
            last=last->next;
            len++;
        }

        if (len>0) k%=len;
        ListNode *ret=NULL;
        for (ListNode *cur=sentinal; len>=k; cur=cur->next, len--)
            if (len==k)
            {
                last->next=head;
                ret=cur->next;
                cur->next=NULL;
            }
        delete sentinal;
        return ret;
    }
};