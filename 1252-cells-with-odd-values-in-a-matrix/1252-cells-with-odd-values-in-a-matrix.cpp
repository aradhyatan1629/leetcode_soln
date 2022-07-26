class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& ind) {
        vector<vector<int>> v(m,vector<int>(n,0));
        int i=0;
        for(i=0;i<ind.size();i++)
        {
            int row = ind[i][0];
            int col = ind[i][1];
            for(int j=0;j<v[row].size();j++)
            {
                v[row][j]++;
            }
            for(int k=0;k<v.size();k++)
            {
                v[k][col]++;
            }
        }
        int cnt=0;
        for(auto r:v)
        {
            for(auto x:r)
            {
                if(x%2!=0)
                {
                    cnt++;
                }
            }
        }
        return cnt;
        
        
        return 0;
    }
};