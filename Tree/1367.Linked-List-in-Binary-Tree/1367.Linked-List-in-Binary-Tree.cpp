class Solution {
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root==NULL) return false;
        else if (dfs(head, root)) return true;
        else if (isSubPath(head, root->left)) return true;
        else if (isSubPath(head, root->right)) return true;
        else return false;
    }
    bool dfs(ListNode *head, TreeNode *node)
    {
        if (node==NULL) return head==NULL;
        else if (head==NULL) return true;
        else if (node->val!=head->val) return false;
        else if (dfs(head->next, node->left)) return true;
        else if (dfs(head->next, node->right)) return true;
        else return false;
    }
};