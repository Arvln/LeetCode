class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>Set;
        while (n>1)
        {
            int num=0;
            while (n>0)
            {
                num+=pow(n%10, 2);
                n/=10;
            }
            if (Set.find(num)==Set.end()) Set.insert(num);
            else return false;
            n=num;
        }
        return true;
    }
};