//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long subarrayRanges(int N, vector<int> &arr) {
        long long sum=0;
        int mx=INT_MIN,mn=INT_MAX;
        for(int i=0;i<N;i++)
        {
            for(int j=i;j<N;j++)
            {
                mx = max(mx,arr[j]);
                mn = min(mn,arr[j]);
                sum+=(mx-mn);
            }
            mx=INT_MIN,mn=INT_MAX;
        }
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> arr(N);
        for (int i = 0; i < N; i++) cin >> arr[i];

        Solution obj;
        cout << obj.subarrayRanges(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends