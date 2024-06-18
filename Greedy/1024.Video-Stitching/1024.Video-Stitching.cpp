class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        int reach=0, ret=0;
        for (int i=0; i<clips.size();)
        {
            int next=reach;
            while (i<clips.size()&&clips[i][0]<=reach)
            {
                next=max(next, clips[i][1]);
                i++;
            }
            ret++;

            if (next>=time) return ret;
            else if (next==reach) return -1;
            reach=next;
        }
        return -1;
    }
};