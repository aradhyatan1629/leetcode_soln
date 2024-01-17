class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>> v(n,vector<int>(n,0));
        int x=n-1,y=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                v[i][j] = matrix[x][y];
                x--;
            }
            x=n-1,y++;
        }
        matrix=v;
    }
};