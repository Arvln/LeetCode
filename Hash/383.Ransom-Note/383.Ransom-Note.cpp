class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int>counts(26);
        for (char c : magazine)
            counts[c-'a']++;
        for (char c : ransomNote)
            if (counts[c-'a']>0) counts[c-'a']--;
            else return false;
        return true;
    }
};