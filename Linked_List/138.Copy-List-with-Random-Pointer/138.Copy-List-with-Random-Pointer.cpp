class Solution {
    unordered_map<Node*, Node*>Map; // origin node->new node
public:
    Node* copyRandomList(Node* head) {
        if (head==NULL) return NULL;

        Map[head]=new Node(head->val);
        Map[head]->next=copyRandomList(head->next);
        Map[head]->random=Map[head->random];
        return Map[head];
    }
};