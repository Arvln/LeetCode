class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *f=head, *s=head;
        while (f!=NULL&&f->next!=NULL)
        {
            f=f->next->next;
            s=s->next;
        }
        ListNode *back=reverseList(s);
        while (back!=NULL)
        {
            if (head->val!=back->val) return false;

            head=head->next;
            back=back->next;
        }
        return true;
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