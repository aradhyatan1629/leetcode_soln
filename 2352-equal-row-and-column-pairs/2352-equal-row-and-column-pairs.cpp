class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>,int> mp;
        
        int m=grid.size(),n=grid[0].size();
        
        for(int j=0;j<n;j++)
        {
            vector<int> v;
            for(int i=0;i<m;i++)
            {
                v.push_back(grid[i][j]);
            }
            mp[v]++;
        }
        
        int cnt=0;
        for(int i=0;i<m;i++)
        {
            cnt+=mp[grid[i]];
        }
        return cnt;
    }
};








