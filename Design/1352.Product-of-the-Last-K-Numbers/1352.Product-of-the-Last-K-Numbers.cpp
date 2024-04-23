class ProductOfNumbers {
    vector<int>pre{1};
    int n=0;
    int lastZero=0;
public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        n++;
        if (num==0)
        {
            lastZero=n;
            pre.push_back(1);
        }
        else pre.push_back(pre.back()*num);
    }
    
    int getProduct(int k) {
        if (lastZero>n-k) return 0;
        else return pre.back()/pre[n-k];
    }
};