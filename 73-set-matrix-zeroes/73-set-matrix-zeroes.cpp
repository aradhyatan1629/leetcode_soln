class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        unordered_set<int> r;
        unordered_set<int> c;
        for(int i=0;i<m;++i)
        {
            for(int j=0;j<n;++j)
            {
                if(matrix[i][j]==0)
                {
                    r.insert(i);
                    c.insert(j);
                }
            }
        }
        int j=0;
        for(int i=0;i<m;++i)
        {
            for(j=0;j<n;++j)
            {
                if(r.find(i)!=r.end() and c.find(j)!=c.end())
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