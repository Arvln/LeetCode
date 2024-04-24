class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int>ret{1};
        int num=1;
        while (ret.size()<n)
        {
            if (num*10<=n) num*=10;
            else
            {
                while (num+1>n||num%10==9)
                    num/=10;
                num+=1;
            }
            ret.push_back(num);
        }
        return ret;
    }
};