class Solution {
public:
    int findCelebrity(int n) {
        int celebrity=0;
        for (int i=1; i<n; i++)
            if (knows(i, celebrity)==false) celebrity=i;
        
        for (int i=0; i<n; i++)
            if (i!=celebrity&&knows(celebrity, i)==true||knows(i, celebrity)==false) return -1;
        return celebrity;
    }
};