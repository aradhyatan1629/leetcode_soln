class Solution {
public:
    //find transpose and then reverse each row
    
    void transpose(vector<vector<int>> &matrix)
    {
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=i+1;j<matrix[i].size();j++)
            {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(int i=0;i<matrix.size();i++)
        {
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};