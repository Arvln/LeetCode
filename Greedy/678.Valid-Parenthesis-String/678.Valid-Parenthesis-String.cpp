class Solution {
public:
    bool checkValidString(string s) {
        int countMax=0, countMin=0;
        for (char c : s)
        {
            if (c=='(')
            {
                countMax++;
                countMin++;
            }
            else if (c==')')
            {
                countMax--;
                countMin--;
            }
            else
            {
                countMax++;
                countMin--;
            }

            if (countMax<0) return false;
            if (countMin<0) countMin=0;
        }
        return countMin==0;
    }
};