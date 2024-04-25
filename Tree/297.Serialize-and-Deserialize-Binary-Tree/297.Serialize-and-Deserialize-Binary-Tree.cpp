class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (root==NULL) return "#";
        else return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*>q;
        for (int i=0; i<data.size(); i++)
            if (data[i]=='#') q.push(NULL);
            else if (data[i]!=',')
            {
                int j=i;
                while (j<data.size()&&data[j]!=',')
                    j++;
                q.push(new TreeNode(stoi(data.substr(i, j-i))));
                i=j;
            }
        return dfs(q);
    }
    TreeNode* dfs(queue<TreeNode*> &q)
    {
        TreeNode *node=q.front();
        q.pop();

        if (node==NULL) return NULL;

        node->left=dfs(q);
        node->right=dfs(q);
        return node;
    }
};