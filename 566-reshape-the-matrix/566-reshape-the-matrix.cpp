class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m = mat.size();
        int n = mat[0].size();
        if(m*n!=r*c)
        {
            return mat;
        }
        vector<vector<int>> v(r,vector<int>(c));
        vector<int> v1;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                v1.push_back(mat[i][j]);
            }
        }
        int k=0;
        for(int i=0;i<r;++i)
        {
            for(int j=0;j<c;++j)
            {
                v[i][j] = v1[k++];
            }
        }
        return v;
    }
};