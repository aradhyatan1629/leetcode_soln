class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int i=0,j=0;
        int cnt=0;
        int m = grid.size();
        int n=grid[0].size();
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;++j)
            {
                if(grid[i][j]<0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};