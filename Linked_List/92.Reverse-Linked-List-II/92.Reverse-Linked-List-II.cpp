class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *sentinal=new ListNode(), *cur=sentinal;
        ListNode *leftNode;
        int i=1;
        while (head!=NULL)
        {
            ListNode *next=head->next;
            head->next=NULL;

            if (i>=left&&i<=right)
            {
                head->next=cur->next;
                cur->next=head;
                if (i==left) leftNode=head;
                if (i==right) cur=leftNode;
            }
            else
            {
                cur->next=head;
                cur=cur->next;
            }
            i++;
            head=next;
        }
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};