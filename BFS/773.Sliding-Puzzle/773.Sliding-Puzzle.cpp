class Solution {
    int dirs[4][2]{{1,0},{0,1},{-1,0},{0,-1}};
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string puzzle;
        int idx;
        for (int i=0; i<2; i++)
            for (int j=0; j<3; j++)
            {
                puzzle.push_back('0'+board[i][j]);
                if (board[i][j]==0) idx=3*i+j;
            }
        
        queue<pair<string, int>>q;
        unordered_set<string>visited;
        q.push({puzzle, idx});
        visited.insert(puzzle);
        int ret=0;
        while (!q.empty())
        {
            for (int size=q.size(); size>0; size--)
            {
                auto [state, idx]=q.front();
                q.pop();

                if (state=="123450") return ret;

                for (auto dir : dirs)
                {
                    int x=idx/3+dir[0], y=idx%3+dir[1];

                    if (x<0||y<0||x>=2||y>=3) continue;
                    
                    string next=state;
                    swap(next[idx], next[3*x+y]);
                    if (visited.find(next)!=visited.end()) continue;

                    q.push({next, 3*x+y});
                    visited.insert(next);
                }
            }
            ret++;
        }
        return -1;
    }
};