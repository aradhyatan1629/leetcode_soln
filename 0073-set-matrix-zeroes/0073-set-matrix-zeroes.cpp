class Solution {
public:
    
    /*
    intuition - we need to know which coordinates have 0 so that we can change all its row and cloumn to 0. So we will use our 0th idex row i.e first row and 0th index column i.e first column as a flag.
    */
    
    void setZeroes(vector<vector<int>>& matrix) {
        bool firstRow = false, firstCol = false;
        int m = matrix.size(),n=matrix[0].size();
        for(int j=0;j<n;j++)
        {
            if(matrix[0][j]==0)
            {
                firstRow = true;
                break;
            }
        }
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                firstCol = true;
                break;
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0 or matrix[0][j]==0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(firstRow)
        {
            for(int j=0;j<n;j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(firstCol)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};


























