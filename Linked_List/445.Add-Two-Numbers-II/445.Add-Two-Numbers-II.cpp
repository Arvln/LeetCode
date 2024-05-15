class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int>s1, s2;
        while (l1!=NULL)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while (l2!=NULL)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        ListNode *sentinal=new ListNode();
        for (int sum=0; !s1.empty()||!s2.empty()||sum>0; sum/=10)
        {
            if (!s1.empty())
            {
                sum+=s1.top();
                s1.pop();
            }
            if (!s2.empty())
            {
                sum+=s2.top();
                s2.pop();
            }
            sentinal->next=new ListNode(sum%10, sentinal->next);
        }
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};