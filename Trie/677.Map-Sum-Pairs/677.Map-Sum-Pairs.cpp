class MapSum {
    class Node {
    public:
        int val=0;
        Node *next[26];
    };
    unordered_map<string, int>Map;
    Node *root;
public:
    MapSum() {
        root=new Node();
    }
    
    void insert(string key, int val) {
        int diff=val-Map[key];
        Map[key]=val;
        Node *cur=root;
        for (char c : key)
        {
            if (cur->next[c-'a']==NULL) cur->next[c-'a']=new Node();
            cur=cur->next[c-'a'];
            cur->val+=diff;
        }
    }
    
    int sum(string prefix) {
        Node *cur=root;
        for (char c : prefix)
        {
            if (cur->next[c-'a']==NULL) cur->next[c-'a']=new Node();
            cur=cur->next[c-'a'];
        }
        return cur->val;
    }
};