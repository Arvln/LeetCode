class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *nextHead=head;
        for (int count=k; count>0; count--)
            if (nextHead==NULL) return head;
            else nextHead=nextHead->next;

        ListNode *end=head;
        head=reverseList(head, nextHead);
        end->next=reverseKGroup(nextHead, k);
        return head;
    }
    ListNode* reverseList(ListNode *node, ListNode *endNode)
    {
        if (node==NULL||node->next==endNode) return node; 

        ListNode *ret=reverseList(node->next, endNode);
        node->next->next=node;
        node->next=NULL;
        return ret;
    }
};