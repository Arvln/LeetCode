class Solution {
    unordered_map<string, vector<pair<string, double>>>map;
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        for (int i=0; i<equations.size(); i++)
        {
            string a=equations[i][0], b=equations[i][1];
            map[a].push_back({b, values[i]});
            map[b].push_back({a, 1.0/values[i]});
        }

        vector<double>ret;
        for (vector<string> query : queries)
        {
            string c=query[0], d=query[1];
            if (map.find(c)==map.end()||map.find(d)==map.end())
            {
                ret.push_back(-1.0);
                continue;
            }
            unordered_set<string>visited({c});
            ret.push_back(dfs(c, d, visited));
        }
        return ret;
    }
    double dfs(string i, string j, unordered_set<string>&visited)
    {
        if (i==j) return 1.0;

        for (auto [k, i_k] : map[i])
        {
            if (k==j) return i_k;
            if (visited.find(k)!=visited.end()) continue;

            visited.insert(k);
            double k_j=dfs(k, j, visited);
            visited.erase(k);
            if (k_j!=-1) return i_k*k_j;
        }
        return -1;
    }
};