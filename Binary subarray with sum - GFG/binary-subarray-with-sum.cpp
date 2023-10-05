//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    int numberOfSubarrays(vector<int>& arr, int N, int target){
        int sum=0;
        unordered_map<int,int> m;
        int cnt=0;
        for(int i=0;i<arr.size();i++)
        {
            sum+=arr[i];
            if(sum==target)
            {
                cnt++;
            }
            if(m[sum-target]>0)
            {
                cnt+=m[sum-target];
            }
            m[sum]++;
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int target; 
        cin >> target;
        vector<int> arr(N);
        for(int i=0; i<N; i++)
            cin >> arr[i];
        Solution obj;
        cout<<obj.numberOfSubarrays(arr, N, target)<<endl;
    }
    return 0;
}
// } Driver Code Ends