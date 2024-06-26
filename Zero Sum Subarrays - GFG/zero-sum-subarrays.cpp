//{ Driver Code Starts
//Initial function template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to count subarrays with sum equal to 0.
    long long int findSubarray(vector<long long int> &arr, int n ) {
        long long int ans=0,cnt=0;
        unordered_map<int,int> m;
        vector<int> pre(n,0);
        pre[0]=arr[0];
        for(int i=1;i<n;++i)
        {
            pre[i]=pre[i-1]+arr[i];
        }
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i]==0)
            {
                cnt++;
            }
            if((m[pre[i]]-0)>0)
            {
                cnt+=m[pre[i]-0];
            }
            m[pre[i]]++;
        }
        return cnt;
    }
};

/*
6 5 2 6 4 6 12 0 -7
*/



//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //input size of array
       
        vector<long long int> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; //input array elements
        Solution ob;
        cout << ob.findSubarray(arr,n) << "\n";
    }
	return 0;
}
// } Driver Code Ends