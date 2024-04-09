class ZigzagIterator {
    vector<int>v1, v2;
    int i, j;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1=v1;
        this->v2=v2;
        i=0;
        j=0;
    }

    int next() {
        if (i==v1.size())
        {
            j++;
            return v2[j-1];
        }
        else if (j==v2.size())
        {
            i++;
            return v1[i-1];
        }
        else if (i==j)
        {
            i++;
            return v1[i-1];
        }
        else
        {
            j++;
            return v2[j-1];
        }
    }

    bool hasNext() {
        return i<v1.size()||j<v2.size();
    }
};