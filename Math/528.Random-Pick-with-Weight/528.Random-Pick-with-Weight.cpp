class Solution {
    vector<int>pre;
    int sum=-1;
public:
    Solution(vector<int>& w) {
        for (int i=0; i<w.size(); i++)
        {
            sum+=w[i];
            pre.push_back(sum);
        }
    }
    
    int pickIndex() {
        int r=rand()%(sum+1);
        auto it=lower_bound(pre.begin(), pre.end(), r);
        return it-pre.begin();
    }
};