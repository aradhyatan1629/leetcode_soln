class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        vector<pair<int,int>> r;
        vector<pair<int,int>> c;
        int m=grid.size(),n=grid[0].size();
        vector<vector<int>> diff(m,vector<int>(n,0));
        for(int i=0;i<m;++i)
        {
            int row_one = accumulate(grid[i].begin(),grid[i].end(),0);
            int row_zero = n-row_one;
            r.push_back({row_one,row_zero});
        }
        for(int j=0;j<n;++j)
        {
            int col_one=0;
            int col_zero=0;
            for(int i=0;i<m;++i)
            {
                if(grid[i][j]==1)
                {
                    col_one++;
                }
            }
            col_zero=m-col_one;
            c.push_back({col_one,col_zero});
        }
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                diff[i][j] = r[i].first + c[j].first - r[i].second - c[j].second;
            }
        }
        return diff;
    }
};

