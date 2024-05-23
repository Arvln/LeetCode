class Solution {
    int M=1337;
public:
    int superPow(int a, vector<int>& b) {
        if (b.empty()) return 1;
        a%=M;
        int back=b.back()%M;
        b.pop_back();
        return Pow(a, back)*Pow(superPow(a, b), 10)%M;
    }
    int Pow(int a, int b)
    {
        if (b==0) return 1;
        else if (b%2==1) return a*Pow(a, b-1)%M;
        else
        {
            int temp=Pow(a, b/2);
            return temp*temp%M;
        }
    }
};