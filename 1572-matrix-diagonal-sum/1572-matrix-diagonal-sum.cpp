class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int i=0,j=0;
        int sum=0;
        while(i<mat.size())
        {
            sum+=mat[i][j];
            i++;
            j++;
        }
        i=0,j=mat[0].size()-1;
        while(i<mat.size())
        {
            sum+=mat[i][j];
            i++;
            j--;
        }
        if(mat.size()%2!=0)
        {
            sum -= mat[mat.size()/2][mat.size()/2];
        }
        return sum;
    }
};