class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> m;
        unordered_map<int,int> row,col;
        
        int n1 = mat.size();
        int n = mat[0].size();
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n;j++)
            {
                m[mat[i][j]] = {i,j};
            }
        }
        
        for(int i=0;i<arr.size();i++)
        {
            int r = m[arr[i]].first;
            int c = m[arr[i]].second;
            
            row[r]++;
            col[c]++;
            
            if(row[r]==n or col[c]==n1)
            {
                return i;
            }
        }
        return 0;
    }
};