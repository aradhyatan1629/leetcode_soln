class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        unordered_map<int,vector<int>> r;
        unordered_map<int,vector<int>> c;
        int cnt=0;
        for(int i=0;i<grid.size();i++)
        {
            vector<int> v;
            vector<int> v1;
            for(int j=0;j<grid[i].size();j++)
            {
                v.push_back(grid[i][j]);
                v1.push_back(grid[j][i]);
            }
            r[i]=v;
            c[i]=v1;
        }
        for(auto x:r)
        {
            for(auto y:c)
            {
                if(x.second==y.second)
                {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};







