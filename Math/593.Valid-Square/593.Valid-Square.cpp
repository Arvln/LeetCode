class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<long>set;
        set.insert(distance(p1, p2));
        set.insert(distance(p1, p3));
        set.insert(distance(p1, p4));
        set.insert(distance(p2, p3));
        set.insert(distance(p2, p4));
        set.insert(distance(p3, p4));

        if (set.size()!=2) return false;
        if (set.find(0)!=set.end()) return false;
        return true;
    }
    long distance(vector<int>& a, vector<int>& b)
    {
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
};