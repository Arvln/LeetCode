class Solution {
    unordered_map<int, vector<TreeNode*>>memo;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n==1) return {new TreeNode()};
        else if (memo.find(n)!=memo.end()) return memo[n];

        vector<TreeNode*>ret;
        for (int i=1; i<n-1; i++)
            if (i%2==1)
                for (TreeNode *left : allPossibleFBT(i))
                    for (TreeNode *right : allPossibleFBT(n-1-i))
                        ret.push_back(new TreeNode(0, left, right));
        memo[n]=ret;
        return ret;
    }
};