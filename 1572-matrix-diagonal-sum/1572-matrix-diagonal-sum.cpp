class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(i==j or i+j == mat.size()-1)
                {
                    sum+=mat[i][j];
                }
            }
        }
        return sum;
    }
};


/*


1 2 3 
3 4 3
5 6 7

1 2 3 4 9
4 5 6 7 9
1 2 3 4 9
4 5 6 7 9
1 1 1 1 1


*/