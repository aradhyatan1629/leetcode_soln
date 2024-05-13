class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        unordered_map<int,int> mp;
        
        for(int i=0;i<m;i++)
        {
            bool flag;
            flag = (grid[i][0] == 1) ? true : false;
            for(int j=0;j<n;j++)
            {
                if(flag)
                {
                    if(grid[i][j]==1)grid[i][j]=0;
                    else grid[i][j]=1;
                    if(grid[i][j]==0)mp[j]++;
                }
                else if(grid[i][j] == 0)
                    mp[j]++;
            }
        }
        
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                if(mp[j] > m/2)
                {
                    if(grid[i][j]==1)grid[i][j]=0;
                    else grid[i][j]=1;
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<m;i++)
        {
            int num = 0;
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 1)
                    num += pow(2,n-j-1);
            }
            ans += num;
        }
        return ans;
    }
};