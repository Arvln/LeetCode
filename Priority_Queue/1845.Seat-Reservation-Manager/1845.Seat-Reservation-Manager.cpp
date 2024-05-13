class SeatManager {
    priority_queue<int, vector<int>, greater<>>pq;
public:
    SeatManager(int n) {
        while (n>0)
        {
            pq.push(n);
            n--;
        }
    }
    
    int reserve() {
        int seat=pq.top();
        pq.pop();
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};