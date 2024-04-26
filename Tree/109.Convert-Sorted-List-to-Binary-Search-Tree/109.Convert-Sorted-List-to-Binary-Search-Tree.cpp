class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head==NULL) return NULL;
        else if (head->next==NULL) return new TreeNode(head->val);

        ListNode *fast=head, *slow=head, *prev;
        while (fast!=NULL&&fast->next!=NULL)
        {
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
        prev->next=NULL;
        return new TreeNode(
            slow->val,
            sortedListToBST(head),
            sortedListToBST(slow->next)
        );
    }
};