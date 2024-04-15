class Solution {
public:
    void reorderList(ListNode* head) {
        ListNode *sentinal=new ListNode(0, head);
        ListNode *fast=sentinal, *slow=fast;
        while (fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        ListNode *back=reverseList(slow->next);
        slow->next=NULL;
        ListNode *front=sentinal->next;
        ListNode *cur=sentinal;
        while (front!=NULL||back!=NULL)
        {
            if (front!=NULL)
            {
                cur->next=front;
                front=front->next;
                cur=cur->next;
            }
            if (back!=NULL)
            {
                cur->next=back;
                back=back->next;
                cur=cur->next;
            }
        }
        head=sentinal->next;
        delete sentinal;
    }
    ListNode* reverseList(ListNode *node)
    {
        if (node==NULL||node->next==NULL) return node;

        ListNode *ret=reverseList(node->next);
        node->next->next=node;
        node->next=NULL;
        return ret;
    }
};