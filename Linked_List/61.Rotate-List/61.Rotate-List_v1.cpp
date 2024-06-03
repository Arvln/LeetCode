class Solution {
    int len=0, k;
    ListNode *head;
public:
    ListNode* rotateRight(ListNode* head, int k) {
        this->head=head;
        this->k=k;
        return dfs(head);
    }
    ListNode* dfs(ListNode *node)
    {
        if (node==NULL)
        {
            if (len>0) k%=len;
            return NULL;
        }
        len++;
        
        ListNode *ret=dfs(node->next);
        if (node->next==NULL) node->next=head;
        if (k==0)
        {
            ret=node->next;
            node->next=NULL;
        }
        k--;
        return ret;
    }
};