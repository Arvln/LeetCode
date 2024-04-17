class RandomizedSet {
    vector<int>nums;
    unordered_map<int, int>Map; // num->idx
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if (Map.find(val)!=Map.end()) return false;

        Map[val]=nums.size();
        nums.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if (Map.find(val)==Map.end()) return false;

        nums[Map[val]]=nums.back();
        Map[nums.back()]=Map[val];
        nums.pop_back();
        Map.erase(val);
        return true;
    }
    
    int getRandom() {
        return nums[rand()%nums.size()];
    }
};