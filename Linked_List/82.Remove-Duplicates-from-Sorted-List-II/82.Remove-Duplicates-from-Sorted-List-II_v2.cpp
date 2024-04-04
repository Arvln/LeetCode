class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *sentinal=new ListNode(), *cur=sentinal;

        while (head!=NULL)
        {
            ListNode *next=head;
            int count=0;
            while (next!=NULL&&head->val==next->val)
            {
                count++;
                next=next->next;
            }

            if (count==1)
            {
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