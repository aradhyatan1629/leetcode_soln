class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans=0;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                bool flag = false;
                if(grid[i][j]==1)
                {
                    int cnt = 0;
                    for(int k=0;k<m;k++)
                    {
                        if(grid[k][j] == 1)
                        {
                            cnt++;
                        }
                    }
                    if(cnt>1)
                    {
                        ans++;
                        flag=true;
                    }
                    cnt=0;
                    if(!flag)
                    {
                        for(int k=0;k<n;k++)
                        {
                            if(grid[i][k] == 1)
                            {
                                cnt++;
                            }
                        }
                        if(cnt>1)
                        {
                            ans++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};