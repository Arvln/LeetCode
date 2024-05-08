class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *sentinal=new ListNode(), *cur=sentinal;
        while (head!=NULL&&head->next!=NULL)
        {
            ListNode *next=head->next->next;
            
            cur->next=head->next;
            head->next->next=head;
            head->next=NULL;
            cur=head;

            head=next;
        }
        cur->next=head;
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};