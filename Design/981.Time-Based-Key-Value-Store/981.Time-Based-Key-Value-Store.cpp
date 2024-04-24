class TimeMap {
    unordered_map<string, vector<pair<int, string>>>Map; // key->{timestamp, val}
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        Map[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto iter=upper_bound(Map[key].begin(), Map[key].end(), make_pair(timestamp, string(105, 'z')));

        if (iter==Map[key].begin()) return "";
        else
        {
            iter--;
            return iter->second;
        }
    }
};