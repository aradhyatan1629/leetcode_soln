//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to perform case-specific sorting of strings.
    string caseSort(string str, int n)
    {
        string l,u;
        for(int i=0;i<n;++i)
        {
            if(str[i]>=97 and str[i]<=122)
            {
                l+=str[i];
            }
            else
            {
                u+=str[i];
            }
        }
        sort(l.begin(),l.end());
        sort(u.begin(),u.end());
        int low=0,up=0;
        for(int i=0;i<n;++i)
        {
            if(str[i]>=97 and str[i]<=122)
            {
                str[i]=l[low];
                low++;
            }
            else
            {
                str[i]=u[up];
                up++;
            }
        }
        return str;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string str;
		cin>>str;
		Solution obj;
		cout<<obj.caseSort (str, n)<<endl;
	}
}
// } Driver Code Ends