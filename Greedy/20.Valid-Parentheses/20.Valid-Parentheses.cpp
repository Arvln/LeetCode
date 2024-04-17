class Solution {
public:
    bool isValid(string S) {
        string s;
        for (char c : S)
            if (c=='('||c=='{'||c=='[') s.push_back(c);
            else if (s.empty()) return false;
            else if (c==')'&&s.back()!='(') return false;
            else if (c=='}'&&s.back()!='{') return false;
            else if (c==']'&&s.back()!='[') return false;
            else s.pop_back();
        return s.empty(); 
    }
};