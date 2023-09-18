class Solution {
public:
    int lengthLongestPath(string input) {     
        vector<string>files;
        for (int i=0; i<input.size(); i++)
        {
            int j=i;
            while (j<input.size()&&input[j]!='\n')
                j++;
            files.push_back(input.substr(i, j-i));
            i=j;
        }

        vector<string>dir;
        int ret=0;
        for (string file : files)
        {
            int k=0;
            while (k<file.size()&&file[k]=='\t')
                k++;
            
            if (dir.size()<=k) dir.resize(k+1);
            dir[k]=file.substr(k);

            if (dir[k].find('.')!=-1)
            {
                int count=0;
                for (int i=0; i<=k; i++)
                    count+=dir[i].size();
                count+=k;
                ret=max(ret, count);
            }
        }
        return ret;
    }
};