using PIL=pair<int, ListNode*>;
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        priority_queue<PIL, vector<PIL>, greater<>>pq;
        while (head!=NULL)
        {
            ListNode *next=head->next;
            head->next=NULL;
            pq.push({head->val, head});
            head=next;
        }
        ListNode *sentinal=new ListNode(), *cur=sentinal;
        while (!pq.empty())
        {
            cur->next=pq.top().second;
            cur=cur->next;
            pq.pop();
        }
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};