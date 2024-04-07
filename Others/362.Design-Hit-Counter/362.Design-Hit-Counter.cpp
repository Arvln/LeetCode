class HitCounter {
    vector<pair<int, int>>counts; // {timestamp, count}
public:
    HitCounter() {
        counts=vector<pair<int, int>>(300);
    }

    void hit(int timestamp) {
        int time=timestamp%300;
        if (counts[time].first==timestamp)
            counts[time].second++;
        else
        {
            counts[time].first=timestamp;
            counts[time].second=1;
        }
    }

    int getHits(int timestamp) {
        int ret=0;
        for (auto &[time, count] : counts)
            if (time>0&&time>timestamp-300)
                ret+=count;
        return ret;
    }
};