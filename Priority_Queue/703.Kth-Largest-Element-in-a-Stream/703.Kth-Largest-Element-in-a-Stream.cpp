class KthLargest {
    priority_queue<int, vector<int>, greater<>>pq;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k=k;
        for (int num : nums)
            pq.push(num);
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size()>k)
            pq.pop();
        return pq.top();
    }
};