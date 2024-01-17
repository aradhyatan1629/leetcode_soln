class Solution {
public:
    int findNCR(int n,int r)
    {
        long long ans=1;
        for(int i=0;i<r;i++)
        {
            ans = ans * (n-i);
            ans = ans/(i+1);
        }
        return ans;
    }
    
    vector<int> getRow(int rowIndex) {
        int n = rowIndex+1;
        vector<int> v;
        for(int c=1;c<=n;c++)
        {
            v.push_back(findNCR(n-1,c-1));
        }
        return v;
    }
};

