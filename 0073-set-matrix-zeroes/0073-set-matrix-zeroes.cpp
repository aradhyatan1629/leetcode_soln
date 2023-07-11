class Solution {
public:
    //TC - O(m*n)
    //SC - O(1)
    
    void setZeroes(vector<vector<int>>& matrix) {
        bool flagRow0 = false,flagCol0 = false;
        int m = matrix.size(),n=matrix[0].size();
        
        for(int j=0;j<n;j++)            //if there is any 0 in the first row 
        {
            if(matrix[0][j] == 0)
            {
                flagRow0 = true;
                break;
            }
        }
        for(int i=0;i<m;i++)          //if there is any 0 in the first column
        {
            if(matrix[i][0] == 0)
            {
                flagCol0 = true;
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
                if(matrix[i][0] == 0 or matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(flagRow0 == true)               //if there was originally any 0 in the first row 
        {                                  
            for(int j=0;j<n;j++)
            {
                matrix[0][j] = 0;
            }
        }
        if(flagCol0 == true)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};