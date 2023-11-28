class Solution {
public:
    int addRungs(vector<int>& rungs, int dist) {
        int cnt=0;
        
        if(rungs[0] > dist)
        {
            int diff = rungs[0];
            if(diff>dist)
            {
                int rungNeed = diff/dist;
                cnt += (diff%dist==0) ? rungNeed-1 : rungNeed;
            }
        }
        
        for(int i=0;i<rungs.size()-1;i++)
        {
            int diff = rungs[i+1] - rungs[i];
            if(diff>dist)
            {
                int rungNeed = diff/dist;
                cnt += (diff%dist==0) ? rungNeed-1 : rungNeed;
            }
        }
        return cnt;
    }
};



