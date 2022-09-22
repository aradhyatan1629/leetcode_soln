class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        unordered_set<int> r;
        unordered_set<int> c;
        int n=matrix.size();
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix.size();j++)
            {
                if((matrix[i][j]>=1 and matrix[i][j]<=n) and (matrix[j][i]>=1 and matrix[j][j]<=n))
                {
                    r.insert(matrix[i][j]);
                    c.insert(matrix[j][i]);
                }
                else
                {
                    return false;
                }
            }
            if(r.size()!=n or c.size()!=n)
            {
                return false;
            }
            r.clear();
            c.clear();
        }
        return true;
    }
};