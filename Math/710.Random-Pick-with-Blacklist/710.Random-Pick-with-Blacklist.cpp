class Solution {
    unordered_map<int, int>Map; // block->valid
    int size;
public:
    Solution(int n, vector<int>& blacklist) {
        size=n-blacklist.size();
        for (int num : blacklist)
            Map[num]=-1;

        int j=n-1;
        for (auto &num : Map)
            if (num.first<size)
            {
                while (j>=0&&Map.find(j)!=Map.end())
                    j--;
                Map[num.first]=j;
                j--;
            }
    }
    
    int pick() {
        int num=rand()%size;
        if (Map.find(num)==Map.end()) return num;
        else return Map[num];
    }
};