class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *sentinal=new ListNode(), *cur=sentinal;
        for (int k=0; l1!=NULL||l2!=NULL||k>0; k/=10)
        {
            if (l1!=NULL)
            {
                k+=l1->val;
                l1=l1->next;
            }
            if (l2!=NULL)
            {
                k+=l2->val;
                l2=l2->next;
            }
            cur->next=new ListNode(k%10);
            cur=cur->next;
        }
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};