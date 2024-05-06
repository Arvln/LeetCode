class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *s1=new ListNode(), *odd=s1;
        ListNode *s2=new ListNode(), *even=s2;
        int count=1;
        while (head!=NULL)
        {
            ListNode *next=head->next;
            head->next=NULL;
            if (count%2==1)
            {
                odd->next=head;
                odd=odd->next;
            }
            else
            {
                even->next=head;
                even=even->next;
            }
            count++;
            head=next;
        }
        odd->next=s2->next;
        ListNode *ret=s1->next;
        delete s1;
        delete s2;
        return ret;
    }
};