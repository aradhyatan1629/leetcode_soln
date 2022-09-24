class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int r=n;
        int c=n;
        int top=0,bottom=n-1;
        int left=0,right=n-1;
        
        int x=1;
        while(top<=bottom and left<=right)
        {
            for(int i=left;i<=right;i++)
            {
                ans[top][i]=x;
                x++;
            }
            top++;
            for(int i=top;i<=bottom;i++)
            {
                ans[i][right]=x;
                x++;
            }
            right--;
            if(top<=bottom)
            {
                for(int i=right;i>=left;i--)
                {
                    ans[bottom][i]=x;
                    x++;
                }
                bottom--;
            }
            if(left<=right)
            {
                for(int i=bottom;i>=top;i--)
                {
                    ans[i][left]=x;
                    x++;
                }
                left++;
            }
        }
        return ans;
    }
};