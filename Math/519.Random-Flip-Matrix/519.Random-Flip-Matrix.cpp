class Solution {
    int m, n;
    int count;
    unordered_map<int, int>Map;
public:
    Solution(int m, int n) {
        this->m=m;
        this->n=n;
        count=0;
    }
    
    vector<int> flip() {
        int r=rand()%(m*n-count);
        count++;

        int num=r;
        if (Map.find(r)!=Map.end()) num=Map[r];

        Map[r]=m*n-count;
        if (Map.find(m*n-count)!=Map.end()) Map[r]=Map[m*n-count];
        return {num/n, num%n};
    }
    
    void reset() {
        Map.clear();
        count=0;
    }
};