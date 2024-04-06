class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &board,int delRow[],int delCol[])
    {
        vis[row][col]=1;
        int m=board.size(),n=board[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and board[nrow][ncol]=='O')
            {
                dfs(nrow,ncol,vis,board,delRow,delCol);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 or i==m-1 or j==0 or j==n-1) and (!vis[i][j] and board[i][j]=='O'))
                    dfs(i,j,vis,board,delRow,delCol);
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' and !vis[i][j])
                    board[i][j]='X';
            }
        }
    }
};