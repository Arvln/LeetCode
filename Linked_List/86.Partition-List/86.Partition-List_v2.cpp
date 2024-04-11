class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *s1=new ListNode(), *s2=new ListNode();
        ListNode *front=s1, *back=s2;
        while (head!=NULL)
        {
            if (head->val<x)
            {
                front->next=head;
                front=front->next;
            }
            else
            {
                back->next=head;
                back=back->next;
            }
            head=head->next;
        }
        front->next=s2->next;
        back->next=NULL;
        ListNode *ret=s1->next;
        delete s1;
        delete s2;
        return ret;
    }
};