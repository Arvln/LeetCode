class WordDictionary {
    class Node {
        public:
            Node *next[26];
            bool isEnd=false;
    };
    Node *root;
public:
    WordDictionary() {
        root=new Node();
    }
    
    void addWord(string word) {
        Node *cur=root;
        for (char c : word)
        {
            if (cur->next[c-'a']==NULL) cur->next[c-'a']=new Node();
            cur=cur->next[c-'a'];
        }
        cur->isEnd=true;
    }
    
    bool search(string word) {
        return dfs(0, word, root);
    }
    bool dfs(int i, string &s, Node *node)
    {
        if (node==NULL) return false;
        else if (i==s.size()) return node->isEnd;

        char c=s[i];
        if (c=='.')
        {
            for (int j=0; j<26; j++)
                if (node->next[j]!=NULL&&dfs(i+1, s, node->next[j])==true)
                    return true;
            return false;
        }
        else
        {
            return dfs(i+1, s, node->next[c-'a']);
        }
    }
};