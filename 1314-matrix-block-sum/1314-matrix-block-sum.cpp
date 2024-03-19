class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>> pre(m,vector<int>(n,0));
        pre[0][0] = mat[0][0];
        for(int j=1;j<n;j++)
            pre[0][j] = pre[0][j-1] + mat[0][j];
        for(int i=1;i<m;i++)
            pre[i][0] = pre[i-1][0] + mat[i][0];
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                pre[i][j] = (pre[i-1][j]+pre[i][j-1]+mat[i][j])-pre[i-1][j-1];
            }
        }
        
        vector<vector<int>> ans(m,vector<int>(n,0));
        for(int i=0;i<pre.size();i++)
        {
            int r1,c1,r2,c2;
            r1 = (i-k)<0 ? 0 : i-k; r2 = (i+k)>=m ? m-1 : i+k ;
            for(int j=0;j<pre[i].size();j++)
            {
                c1 = (j-k)<0 ? 0 :j-k; c2 = (j+k)>=n ? n-1 : j+k;
                if(r1==0 and c1==0)
                    ans[i][j] = pre[r2][c2];
                else if(r1==0)
                    ans[i][j] = pre[r2][c2]-pre[r2][c1-1];
                else if(c1==0)
                    ans[i][j] = pre[r2][c2]-pre[r1-1][c2];
                else
                    ans[i][j] = (pre[r2][c2]-pre[r1-1][c2]-pre[r2][c1-1]) + pre[r1-1][c1-1];
            }
        }
        return ans;
    }
};


/*

1 2 3
4 5 6
7 8 9

*/