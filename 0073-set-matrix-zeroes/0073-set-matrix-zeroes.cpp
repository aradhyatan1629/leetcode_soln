class Solution {
public:
    //TC - O(m*n + m*n)
    //SC - O(m+n)
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(),n=matrix[0].size();
        vector<int> row(m,-1);
        vector<int> col(n,-1);
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i] = 0;
                    col[j] = 0;
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row[i]==0 or col[j]==0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};