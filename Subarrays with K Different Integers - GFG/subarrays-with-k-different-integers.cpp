//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    
    int atMostK(vector<int> &arr,int k)
    {
        int i=0,j=0,n=arr.size();
        vector<int> v(arr.size()+1,0);
        int cnt=0;
        int size=0;
        while(j<n)
        {
            v[arr[j]]++;
            if(v[arr[j]]==1)
            {
                size++;
            }
            if(size<=k)
            {
                cnt+=(j-i+1);
            }
            else
            {
                while(size>k)
                {
                    v[arr[i]]--;
                    if(v[arr[i]]==0)
                    {
                        size--;
                    }
                    i++;
                }
                cnt+=(j-i+1);
            }
            j++;
        }
        return cnt;
    }
  
    int subarrayCount(vector<int> &arr, int N, int k) {
        return atMostK(arr,k) - atMostK(arr,k-1);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, k;
        cin >> N >> k;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayCount(arr, N, k) << endl;
    }
    return 0;
}
// } Driver Code Ends