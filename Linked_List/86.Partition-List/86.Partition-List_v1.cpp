class Solution {
    ListNode *front, *back;
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *s1=new ListNode();
        ListNode *s2=new ListNode();
        front=s1;
        back=s2;
        dfs(head, x);
        front->next=s2->next;
        back->next=NULL;
        ListNode *ret=s1->next;
        delete s1;
        delete s2;
        return ret;
    }
    void dfs(ListNode *head, int x)
    {
        if (head==NULL) return;
        else if (head->val<x)
        {
            front->next=head;
            front=front->next;
        }
        else
        {
            back->next=head;
            back=back->next;
        }
        dfs(head->next, x);
    }
};