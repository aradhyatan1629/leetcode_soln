class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &grid,int delRow[],int delCol[],int id,int &area)
    {
        grid[r][c] = id;
        area++;
        int n=grid.size();
        for(int i=0;i<4;i++)
        {
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]==1)
                dfs(nrow,ncol,grid,delRow,delCol,id,area);
        }
    }
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        unordered_map<int,int> m; //{id,area}
        int mxArea=0,id=2;
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    int area=0;
                    dfs(i,j,grid,delRow,delCol,id,area);
                    mxArea = max(area,mxArea);
                    m[id] = area;
                    id++;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    int area=1;
                    unordered_set<int> st;
                    for(int k=0;k<4;k++)
                    {
                        int nrow = i + delRow[k];
                        int ncol = j + delCol[k];
                        if(nrow>=0 and nrow<n and ncol>=0 and ncol<n and grid[nrow][ncol]!=0 
                           and st.find(grid[nrow][ncol])==st.end())
                        {
                            area += m[grid[nrow][ncol]];
                            st.insert(grid[nrow][ncol]);
                        }
                    }
                    mxArea = max(area,mxArea);
                }
            }
        }
        return mxArea;
    }
};



/*

we will give id to each connected component
for example for the grid 
1 1 0 
0 0 1 
1 1 0 
we will give id to components as - 
2 2 0
0 0 3
4 4 0

and we will store the area of all these components in a map
after this whenever we encounter a 0 we will check all its 
neighbors and find the maximum area.

*/