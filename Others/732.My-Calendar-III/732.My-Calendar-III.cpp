class MyCalendarThree {
    map<int, int>diff;
public:
    MyCalendarThree() {
        
    }
    
    int book(int startTime, int endTime) {
        diff[startTime]++;
        diff[endTime]--;

        int count=0, ret=0;
        for (auto &[_, shift] : diff)
        {
            count+=shift;
            ret=max(ret, count);
        }
        return ret;
    }
};