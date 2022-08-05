class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& ori, int m, int n) {
        vector<vector<int>> v(m,vector<int>(n,0));
        int k=0;
        if(ori.size()!=m*n)
        {
            return {};
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;++j)
            {
                v[i][j] = ori[k++];
            }
        }
        return v;
    }
};