//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&nums, int n)
    {   
        unordered_map<int,int> m;
        vector<int> pre(n,0);
        pre[0]=nums[0];
        int mx=0;
        for(int i=1;i<n;i++)
        {
            pre[i] = pre[i-1] + nums[i];
        }
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i]==0)
            {
                mx = max(mx,i+1);
            }
            else if(m.find(pre[i])!=m.end())
            {
                mx = max(mx,i-m[pre[i]]);
            }
            else if(m.find(pre[i])==m.end())
            {
                m[pre[i]] = i;
            }
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}



// } Driver Code Ends