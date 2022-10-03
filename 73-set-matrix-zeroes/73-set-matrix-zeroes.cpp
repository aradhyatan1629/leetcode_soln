class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_map<int,int> r;
        unordered_map<int,int> c;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]==0)
                {
                    r[i]=1;
                    c[j]=1;
                }
            }
        }
        int j=0;
        for(int i=0;i<m;++i)
        {
            for(j=0;j<n;++j)
            {
                if(r[i]==1 and c[j]==1)
                {
                    for(int j=0;j<n;++j)
                    {
                        matrix[i][j]=0;
                    }
                    for(int i=0;i<m;++i)
                    {
                        matrix[i][j]=0;
                    }
                }
            }
            r.erase(i);
            c.erase(j);
        }
    }
};