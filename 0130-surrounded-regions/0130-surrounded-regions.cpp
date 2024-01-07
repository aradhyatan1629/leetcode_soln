class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size(),n=board[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<int,int>> q;
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if((i==0 or i==m-1 or j==0 or j==n-1) and board[i][j]=='O')
                {
                    vis[i][j]=1;
                    q.push({i,j});
                }
            }
        }
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
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
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O' and !vis[i][j])
                {
                    board[i][j]='X';
                }
            }
        }
    }
};