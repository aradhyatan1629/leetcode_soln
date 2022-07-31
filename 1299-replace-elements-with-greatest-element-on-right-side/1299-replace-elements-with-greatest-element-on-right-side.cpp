class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int i = n;
        int mx = 0;
        vector<int> v(arr.size(),0);
        for(i=n-1;i>=0;i--)
        {
            if(i==n-1)
            {
                v[i]=-1;
            }
            else 
            {
                if(arr[i+1]>mx)
                {
                    mx=arr[i+1];
                    v[i]=mx;
                }
                else
                {
                    v[i]=mx;
                }
            }
        }
        return v;
    }
};