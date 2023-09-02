class Solution {
public:
    
    void bfs(int i,int j,vector<vector<int>> &vis,vector<vector<char>> &board,int delRow[],int delCol[])
    {
        queue<pair<int,int>> q;
        vis[i][j] = 1;
        q.push({i,j});
        
        int m = board.size(),n=board[0].size();
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            
            for(int i=0;i<4;i++)
            {
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and board[nrow][ncol]=='O')
                {
                    vis[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
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
                if((i==0 or i==m-1 or j==0 or j==n-1) and (!vis[i][j] and board[i][j]=='O'))
                {
                    bfs(i,j,vis,board,delRow,delCol);
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' and vis[i][j]==0)
                {
                    board[i][j] = 'X';
                }
            }
        }
    }
};