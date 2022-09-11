class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans;
        for(int i=0;i<m;++i)
        {
            int sum=0;
            vector<int> v;
            for(int j=0;j<n;++j)
            {
                sum=0;
                int rlow=i-k;
                if(rlow<0)
                {
                    rlow=0;
                }
                int rhigh=i+k;
                if(rhigh>m-1)
                {
                    rhigh=m-1;
                }
                int clow=j-k;
                if(clow<0)
                {
                    clow=0;
                }
                int chigh=j+k;
                if(chigh>n-1)
                {
                    chigh=n-1;
                }
                // cout<<rlow<<" "<<rhigh<<endl;
                // cout<<clow<<" "<<chigh<<endl;
                for(int i=rlow;i<=rhigh;i++)
                {
                    for(int j=clow;j<=chigh;++j)
                    {
                        sum+=mat[i][j];
                    }
                }
                // cout<<"sum: "<<sum<<endl;
                v.push_back(sum);
            }
            ans.push_back(v);
            v.clear();
        }
        return ans;
    }
};