class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<pair<int,int>> v;
        
        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    cnt++;
                }
            }
            v.push_back({cnt,i});
        }
        sort(v.begin(),v.end());
        
        vector<int> ans;
        int i=0;
        while(k--)
        {
            ans.push_back(v[i].second);
            i++;
        }
        return ans;
    }
};


