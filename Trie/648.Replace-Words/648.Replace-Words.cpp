class Solution {
    class Node {
        public:
            Node *next[26];
            bool isEnd=false;
    };
    Node *root;
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        root=new Node();
        for (string word : dictionary)
        {
            Node *node=root;
            for (char c : word)
            {
                if (node->next[c-'a']==NULL) node->next[c-'a']=new Node();
                node=node->next[c-'a'];
            }
            node->isEnd=true;
        }

        int n=sentence.size();
        Node *node=root;
        string ret;
        for (int i=0; i<n; i++)
        {
            ret.push_back(sentence[i]);
            if (sentence[i]!=' ')
            {
                if (node!=NULL)
                {
                    node=node->next[sentence[i]-'a'];
                    if (node!=NULL&&node->isEnd==true)
                    {
                        while (i<n&&sentence[i]!=' ') i++;
                        i--;
                    }
                }
            }
            else node=root;
        }
        return ret;
    }
};