class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        set<pair<int, int>>Set; // {val, idx}
        for (int i=0; i<lists.size(); i++)
            if (lists[i]!=NULL) Set.insert({lists[i]->val, i});
        
        ListNode *sentinal=new ListNode(), *cur=sentinal;
        while (!Set.empty())
        {
            int i=Set.begin()->second;
            cur->next=lists[i];
            cur=cur->next;
            Set.erase(Set.begin());
            if (lists[i]->next!=NULL)
            {
                lists[i]=lists[i]->next;
                Set.insert({lists[i]->val, i});
                cur->next=NULL;
            }
        }
        ListNode *ret=sentinal->next;
        delete sentinal;
        return ret;
    }
};