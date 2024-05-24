class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        stack<pair<int, int>>Stack; // {val, idx}
        vector<int>ret(10001);
        int i=0;
        while (head!=NULL)
        {
            while (!Stack.empty()&&Stack.top().first<head->val)
            {
                ret[Stack.top().second]=head->val;
                Stack.pop();
            }
            Stack.push({head->val, i});
            head=head->next;
            i++;
        }
        ret.resize(i);
        return ret;
    }
};