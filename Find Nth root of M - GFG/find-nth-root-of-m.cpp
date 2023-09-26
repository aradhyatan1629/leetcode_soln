//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	
	long long fun(int mid,int n,int m)
	{
	    long long ans = 1;
	    for(int i=1;i<=n;i++)
	    {
	        ans = ans * mid;
	        if(ans>m)
	        {
	            break;
	        }
	    }
	    return ans;
	}
	
	int NthRoot(int n, int m)
	{
	    int low = 1,high=m;
	    while(low<=high)
	    {
	        int mid = low + (high-low)/2;
	        if(fun(mid,n,m)==m)
	        {
	            return mid;
	        }
	        else if(fun(mid,n,m)<m)
	        {
	            low = mid+1;
	        }
	        else
	        {
	            high=mid-1;
	        }
	    }
	    return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends