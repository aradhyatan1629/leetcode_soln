class Solution {
public:
    /*Intuition - Any O that is on the boundary (1st row,last row 1st col last col)
    of the matrix and is connected to more Os 4 directionally then all those set of
    O's cannot be flipped . so we need to find how many Os on the boundary are connected
    to O's in the inside of the matrix.
    */
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &board,
             int delRow[],int delCol[])
    {
        vis[row][col]=1;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row+delRow[i];
            int ncol = col+delCol[i];
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && 
               board[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,board,delRow,delCol);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 or i==m-1 or j==0 or j==n-1) and board[i][j]=='O')
                {
                    dfs(i,j,vis,board,delRow,delCol);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(!vis[i][j] and board[i][j]=='O')
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};