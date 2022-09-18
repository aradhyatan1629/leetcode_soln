class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size();
        int n=matrix[0].size();
        int i=0,j=n-1;
        //O(n+m) solution
        while(i<m and j>=0) //Out of bound condition
        {
            if(matrix[i][j]==target)
            {
                return true;
            }
            else if(matrix[i][j]>target)
            {
                j--;
            }
            else if(matrix[i][j]<target)
            {
                i++;
            }
        }
        return false;
    }
};

//Note-//Out of bound condition , if we go out of bound then element is not present in matrix