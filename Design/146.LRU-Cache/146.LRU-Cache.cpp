class LRUCache {
    list<int>List; // key
    unordered_map<int, list<int>::iterator>keyToIter;
    unordered_map<int, int>keyToVal;
    int cap;
public:
    LRUCache(int capacity) {
        cap=capacity;
    }
    
    int get(int key) {
        if (keyToVal.find(key)==keyToVal.end()) return -1;

        List.erase(keyToIter[key]);
        List.push_back(key);
        keyToIter[key]=--List.end();
        return keyToVal[key];
    }
    
    void put(int key, int value) {
        if (get(key)!=-1)
        {
            keyToVal[key]=value;
            return;
        }
        else if (List.size()==cap)
        {
            int removedKey=*List.begin();
            List.erase(List.begin());
            keyToIter.erase(removedKey);
            keyToVal.erase(removedKey);
        }

        List.push_back(key);
        keyToIter[key]=--List.end();
        keyToVal[key]=value;
    }
};