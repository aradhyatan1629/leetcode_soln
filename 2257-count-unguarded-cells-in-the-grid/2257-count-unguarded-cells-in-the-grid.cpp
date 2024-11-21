class Solution {
public:
    void solve(int x,int y,vector<vector<int>> &grid){
        
        for(int i=x-1;i>=0;i--){  // up
            if(grid[i][y] == 1 || grid[i][y] == 2)
                break;
            grid[i][y] = 3;
        }
        
        for(int i=x+1;i<grid.size();i++){ // down
            if(grid[i][y] == 1 || grid[i][y] == 2)
                break;
            grid[i][y] = 3;
        }
        
        for(int j=y+1;j<grid[0].size();j++){ // right
            if(grid[x][j] == 1 || grid[x][j] == 2)
                break;
            grid[x][j] = 3;
        }
        
        for(int j=y-1;j>=0;j--){ // left
            if(grid[x][j] == 1 || grid[x][j] == 2)
                break;
            grid[x][j] = 3;
        }
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m,vector<int>(n,0));
        
        for(int i=0;i<guards.size();i++){
            int x = guards[i][0];
            int y = guards[i][1];
            grid[x][y] = 1;
        }
        for(int i=0;i<walls.size();i++){
            int x = walls[i][0];
            int y = walls[i][1];
            grid[x][y] = 2;
        }
        
        int unguarded = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] != 1 && grid[i][j] != 2)
                    unguarded++;
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    solve(i,j,grid);
                }
            }
        }
        
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 3)
                    cnt++;
            }
        }
        return unguarded-cnt;
    }
};

// 1 guard
// 2 wall
// 3 guarded