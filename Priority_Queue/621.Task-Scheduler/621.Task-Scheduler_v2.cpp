class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        n++;
        unordered_map<char, int>Map; // char->count
        for (char c : tasks)
            Map[c]++;
        
        int maxFreq=0;
        for (auto &[_, freq] : Map)
            maxFreq=max(maxFreq, freq);
        int count=0;
        for (auto &[_, freq] : Map)
            if (freq==maxFreq) count++;
        
        return max((maxFreq-1)*n+count, (int)tasks.size());
    }
};