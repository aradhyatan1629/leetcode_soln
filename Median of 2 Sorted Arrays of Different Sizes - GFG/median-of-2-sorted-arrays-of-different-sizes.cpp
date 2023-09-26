//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    double MedianOfArrays(vector<int>& array1, vector<int>& array2)
    {
        int n1 = array1.size(),n2 = array2.size(),n = n1+n2;
        int ind1 = (n/2)-1;
        int ind2 = (n/2);
        int cnt=0;
        int i=0,j=0;
        int ind1e=0,ind2e=0;
        while(i<n1 and j<n2)
        {
            if(array1[i]<=array2[j])
            {
                if(cnt==ind1){ind1e=array1[i];}
                if(cnt==ind2){ind2e=array1[i];}
                cnt++;
                i++;
            }
            else
            {
                if(cnt==ind1){ind1e=array2[j];}
                if(cnt==ind2){ind2e=array2[j];}
                cnt++;
                j++;
            }
        }
        while(i<n1)
        {
            if(cnt==ind1){ind1e=array1[i];}
            if(cnt==ind2){ind2e=array1[i];}
            cnt++;
            i++;
        }
        while(j<n2)
        {
            if(cnt==ind1){ind1e=array2[j];}
            if(cnt==ind2){ind2e=array2[j];}
            cnt++;
            j++;
        }
        if(n%2==1)
        {
            return (double)ind2e;
        }
        return double((double(ind1e+ind2e))/2.0);
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i){
            cin>>array2[i];
        }
        Solution ob;
        cout<<ob.MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}



// } Driver Code Ends