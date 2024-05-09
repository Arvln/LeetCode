class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int ret=0, surplus=0, diff=0;
        for (int i=0; i<gas.size(); i++)
        {
            surplus+=gas[i]-cost[i];
            diff+=gas[i]-cost[i];

            if (surplus<0)
            {
                surplus=0;
                ret=i+1;
            }
        }

        if (diff<0) return -1;
        else return ret;
    }
};