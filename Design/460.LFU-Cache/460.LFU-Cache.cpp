class LFUCache {
    unordered_map<int, int>keyToVal;
    unordered_map<int, int>keyToFreq;
    unordered_map<int, list<int>::iterator>keyToIter;
    unordered_map<int, list<int>>freqToList;
    int cap, minFreq;
public:
    LFUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if (keyToVal.find(key)==keyToVal.end()) return -1;

        int freq=keyToFreq[key];
        keyToFreq[key]++;
        freqToList[freq].erase(keyToIter[key]);
        freqToList[freq+1].push_back(key);
        keyToIter[key]=--freqToList[freq+1].end();
        if (freqToList[minFreq].empty()) minFreq++;
        return keyToVal[key];
    }
    
    void put(int key, int value) {
        if (get(key)!=-1)
        {
            keyToVal[key]=value;
            return;
        }
        else if (keyToVal.size()==cap)
        {
            int delKey=*freqToList[minFreq].begin();
            keyToVal.erase(delKey);
            keyToFreq.erase(delKey);
            keyToIter.erase(delKey);
            freqToList[minFreq].erase(freqToList[minFreq].begin());
        }

        keyToVal[key]=value;
        keyToFreq[key]=1;
        freqToList[1].push_back(key);
        keyToIter[key]=--freqToList[1].end();
        minFreq=1;
    }
};