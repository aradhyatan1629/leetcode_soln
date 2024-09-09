class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(),n=matrix[0].size();
        
        int i=0,j=0;
        int rowStart=0,colStart=0;
        int rowEnd=m-1,colEnd=n-1;
            
        while(rowStart<=rowEnd && colStart<=colEnd){
            
            for(int j=colStart;j<=colEnd;j++){
                ans.push_back(matrix[rowStart][j]);
            }
            for(int i=rowStart+1;i<=rowEnd;i++){
                ans.push_back(matrix[i][colEnd]);
            }
            if (rowStart < rowEnd) {
                for (int j = colEnd - 1; j >= colStart; j--) {
                    ans.push_back(matrix[rowEnd][j]);
                }
            }
            if (colStart < colEnd) {
                for (int i = rowEnd - 1; i > rowStart; i--) {
                    ans.push_back(matrix[i][colStart]);
                }
            }
            
            rowStart++,colStart++;
            rowEnd--,colEnd--;
            
        }
        return ans;
        
    }
};




/*
1st iter - row-0,col-changing

1 2 3 4 0 0
5 6 7 8 0 0
3 7 1 3 0 0
1 2 0 4 0 0
0 0 0 0 0 0






0 to






















*/



