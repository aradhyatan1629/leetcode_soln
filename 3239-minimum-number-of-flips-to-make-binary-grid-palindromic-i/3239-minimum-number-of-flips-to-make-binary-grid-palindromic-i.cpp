class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size(),n=grid[0].size();
        int mnRow = INT_MAX;
        
        int flips = 0;
        for(int i=0;i<m;i++)
        {
            int startCol = 0;
            int endCol = n-1;
            while(startCol<endCol)
            {
                if(grid[i][startCol] != grid[i][endCol])
                    flips++;
                startCol++;
                endCol--;
            }
        }
        mnRow = min(mnRow,flips);
        flips = 0;
        int mnCol = INT_MAX;
        
        for(int j=0;j<n;j++)
        {
            int startRow = 0;
            int endRow = m-1;
            while(startRow < endRow)
            {
                if(grid[startRow][j] != grid[endRow][j])
                    flips++;
                startRow++,endRow--;
            }
        }
        mnCol = min(mnCol,flips);
        return min(mnRow,mnCol);
    }
};