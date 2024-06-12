class Solution {
public:
    char findTheDifference(string s, string t) {
        char ret=t.back();
        for (int i=0; i<s.size(); i++) ret^=s[i]^t[i];
        return ret;
    }
};