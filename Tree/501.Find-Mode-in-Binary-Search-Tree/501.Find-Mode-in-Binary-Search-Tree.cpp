/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int prev, count, max_count;
    vector<int>ret;
public:
    vector<int> findMode(TreeNode* root) {
        prev=-100000;
        count=0, max_count=0;
        dfs(root);
        return ret;
    }
    void dfs(TreeNode* root)
    {
        if (root==NULL) return;

        dfs(root->left);
        if (prev==root->val)
            count+=1;
        else
            count=1;
        prev=root->val;
        if (count>max_count)
        {
            max_count=count;
            ret.clear();
            ret.push_back(root->val);
        }
        else if (count==max_count)
            ret.push_back(root->val);
        dfs(root->right);
    }
};