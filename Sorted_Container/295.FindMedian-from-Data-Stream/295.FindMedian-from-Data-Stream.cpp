class MedianFinder {
    multiset<int>Set;
    multiset<int>::iterator median;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        Set.insert(num);

        int size=Set.size();
        if (size==1) median=Set.begin();
        else if (size%2==1)
        {
            if (num>=*median) median=next(median, 1);
        }
        else
        {
            if (num<*median) median=prev(median, 1);
        }
    }
    
    double findMedian() {
        if (Set.size()%2==1) return *median;
        else return (*median+*next(median, 1))/2.0;
    }
};