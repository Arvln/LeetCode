class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int>Map{
            {'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}
        }; // char->code

        int R=4, Q=1e9+7;
        long RL=1;
        for (int i=0; i<9; i++)
            RL=(RL*R)%Q;
        
        int l=0, r=0;
        long hash=0;
        unordered_set<long>visited;
        unordered_set<string>ret;
        while (r<s.size())
        {
            hash=(hash*R%Q+Map[s[r]])%Q;
            r++;

            if (r-l==10)
            {
                if (visited.find(hash)==visited.end()) visited.insert(hash);
                else ret.insert(s.substr(l, r-l));

                hash=(hash-RL*Map[s[l]]%Q+Q)%Q;
                l++;
            }
        }
        return vector<string>(ret.begin(), ret.end());
    }
};