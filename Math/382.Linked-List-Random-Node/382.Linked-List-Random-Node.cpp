class Solution {
    ListNode *node;
public:
    Solution(ListNode* head) {
        node=head;
    }
    
    int getRandom() {
        ListNode *head=node;
        int ret;
        int k=0;

        while (head!=NULL)
        {
            k++;
            int r=rand()%k;
            if (r==0) ret=head->val;
            head=head->next;
        }
        return ret;
    }
};