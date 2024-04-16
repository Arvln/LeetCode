class Solution {
    vector<vector<int>>nexts;
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        nexts=vector<vector<int>>(501);
        dfs(root, NULL);
        queue<int>q;
        vector<int>visited(501, 0);
        q.push(target->val);
        visited[target->val]=1;
        vector<int>rets;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                int cur=q.front();
                q.pop();

                if (k==0) rets.push_back(cur);

                for (int next : nexts[cur])
                {
                    if (visited[next]==1) continue;

                    q.push(next);
                    visited[next]=1;
                }
            }
            k--;
        }
        return rets;
    }
    void dfs(TreeNode *node, TreeNode *parent)
    {
        if (node==NULL) return;

        if (node->left!=NULL) nexts[node->val].push_back(node->left->val);
        if (node->right!=NULL) nexts[node->val].push_back(node->right->val);
        if (parent!=NULL) nexts[node->val].push_back(parent->val);

        dfs(node->left, node);
        dfs(node->right, node);
    }
};