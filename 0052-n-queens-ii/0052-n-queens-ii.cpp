class Solution {
public:
    
    bool check(int i,int j,vector<string> &board){
        int n = board.size();
        int row = i;
        int col = j;
        
        while(row>=0 && col>=0){          // upper left diagonal
            if(board[row][col] == 'Q')
                return false;
            row--,col--;
        }
        
        row=i,col=j;
        while(col>=0){                  // left columns
            if(board[row][col] == 'Q')
                return false;
            col--;
        }
        
        row=i,col=j;
        while(row<n && col>=0){          // lower left diagonal
            if(board[row][col] == 'Q')
                return false;
            row++;
            col--;
        }
        
        return true;
    }
    
    void solve(int col,int n,vector<string> &board,vector<vector<string>> &ans){
        if(col >= n){
            ans.push_back(board);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(check(i,col,board)){
                board[i][col] = 'Q';
                solve(col+1,n,board,ans);
                board[i][col] = '.';
            }
        }
    }
    
    int totalNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n);
        string s(n,'.');
        
        for(int i=0;i<board.size();i++)
            board[i] = s;
        
        solve(0,n,board,ans);
        
        return ans.size();
    }
};