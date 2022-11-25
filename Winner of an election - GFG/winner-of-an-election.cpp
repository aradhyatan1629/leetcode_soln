//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[],int n)
    {
        unordered_map<string,int> m;
        for(int i=0;i<n;++i)
        {
            m[arr[i]]++;
        }
        int mx=0;
        string ans;
        vector<string> v;
        for(auto x:m)
        {
            if(ans=="")
            {
                ans=x.first;
                mx=x.second;
            }
            else if(x.second>mx)
            {
                ans=x.first;
                mx=x.second;
            }
            else if(x.second==mx and x.first<ans)
            {
                ans=x.first;
            }
        }
        v.push_back(ans);
        v.push_back(to_string(mx));
        return v;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends