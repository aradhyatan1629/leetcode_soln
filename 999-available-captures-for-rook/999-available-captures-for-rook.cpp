class Solution {
public:
    int numRookCaptures(vector<vector<char>>& bd) {
        int x=0,y=0;
        int cnt=0;
        int totalcnt=0;
        for(int i=0;i<bd.size();i++)
        {
            for(int j=0;j<bd[i].size();j++)
            {
                if(bd[i][j]=='R')
                {
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        for(int j=y-1;j>=0;j--)
        {
            if(bd[x][j]=='B')
            {
                break;
            }
            else if(bd[x][j]=='p')
            {
                cnt++;
                break;
            }
        }
        totalcnt+=cnt;
        cnt=0;
        for(int j=y+1;j<8;++j)
        {
            if(bd[x][j]=='B')
            {
                break;
            }
            else if(bd[x][j]=='p')
            {
                cnt++;
                break;
            }
        }
        totalcnt+=cnt;
        cnt=0;
        for(int i=x-1;i>=0;i--)
        {
            if(bd[i][y]=='B')
            {
                break;
            }
            else if(bd[i][y]=='p')
            {
                cnt++;
                break;
            }
        }
        totalcnt+=cnt;
        cnt=0;
        for(int i=x+1;i<8;i++)
        {
            if(bd[i][y]=='B')
            {
                break;
            }
            else if(bd[i][y]=='p')
            {
                cnt++;
                break;
            }
        }
        totalcnt+=cnt;
        return totalcnt;
    }
};