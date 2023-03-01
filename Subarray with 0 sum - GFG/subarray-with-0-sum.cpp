//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        vector<int> v(arr,arr+n);
        vector<int> pre(n,0);
        int cnt = count(v.begin(),v.end(),0);
        if(cnt>=1)
        {
            return true;
        }
        unordered_map<int,int> m;
        pre[0]=v[0];
        for(int i=1;i<v.size();i++)
        {
            pre[i]=pre[i-1]+arr[i];
        }
        for(int i=0;i<pre.size();i++)
        {
            if(pre[i]==0)
            {
                return true;
            }
            else if(m[pre[i]]>0)
            {
                return true;
            }
            m[pre[i]]++;
        }
        return false;
    }
};


// 4 6 3 4 10
// 4 6 6 7 13






//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends