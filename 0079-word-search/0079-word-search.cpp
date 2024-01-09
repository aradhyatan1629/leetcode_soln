class Solution {
public:
    
    bool dfs(int row,int col,vector<vector<char>> &board,string &word,int delRow[],int delCol[],int index,vector<vector<int>> &vis)
    {
        if(index==word.size()-1)
        {
            return true;
        }
        vis[row][col] = 1;
        int m = board.size(),n=board[0].size();
        for(int i=0;i<4;i++)
        {
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            if(nrow>=0 and nrow<m and ncol>=0 and ncol<n and !vis[nrow][ncol] and board[nrow][ncol]==word[index+1])
            {
                if(dfs(nrow,ncol,board,word,delRow,delCol,index+1,vis))
                {
                    return true;
                }
            }
        }
        vis[row][col] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size(),n=board[0].size();
        int delRow[] = {-1,0,+1,0};
        int delCol[] = {0,+1,0,-1};
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j] == word[0])
                {
                    vector<vector<int>> vis(m,vector<int>(n,0));
                    if(dfs(i,j,board,word,delRow,delCol,0,vis))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};