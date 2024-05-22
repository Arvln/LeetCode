class Solution {
public:
    bool isPalindrome(string s) {
        string S;
        for (char c : s)
            if (isalnum(c)) S.push_back(tolower(c));
        s=S;

        for (int i=0, j=s.size()-1; i<j; i++, j--)
            if (s[i]!=s[j]) return false;
        return true;
    }
};