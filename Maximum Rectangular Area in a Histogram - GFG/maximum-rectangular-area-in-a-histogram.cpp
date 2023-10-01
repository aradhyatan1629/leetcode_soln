//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    
    vector<long long> NSR(long long arr[],int n)
    {
        vector<long long> v;
        stack<pair<long long,long long>> st;
        for(int i=n-1;i>=0;i--)
        {
            if(st.empty())
            {
                v.push_back(n);
            }
            else if(!st.empty() and st.top().first<arr[i])
            {
                v.push_back(st.top().second);
            }
            else if(!st.empty() and st.top().first>=arr[i])
            {
                while(!st.empty() and st.top().first>=arr[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    v.push_back(n);
                }
                else
                {
                    v.push_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        reverse(v.begin(),v.end());
        return v;
    }
    
    vector<long long> NSL(long long arr[],int n)
    {
        vector<long long> v;
        stack<pair<long long,long long>> st;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                v.push_back(-1);
            }
            else if(!st.empty() and st.top().first<arr[i])
            {
                v.push_back(st.top().second);
            }
            else if(!st.empty() and st.top().first>=arr[i])
            {
                while(!st.empty() and st.top().first>=arr[i])
                {
                    st.pop();
                }
                if(st.empty())
                {
                    v.push_back(-1);
                }
                else
                {
                    v.push_back(st.top().second);
                }
            }
            st.push({arr[i],i});
        }
        return v;
    }
    
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> nsr = NSR(arr,n);
        vector<long long> nsl = NSL(arr,n);
        vector<long long> widths;
        for(int i=0;i<nsl.size();i++)
        {
            widths.push_back(nsr[i]-nsl[i]-1);
        }
        long long mx=0;
        for(int i=0;i<widths.size();i++)
        {
            mx = max(mx,arr[i]*widths[i]);
        }
        return mx;
    }
};


//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}

// } Driver Code Ends