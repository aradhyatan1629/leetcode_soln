//{ Driver Code Starts
#include <iostream>
using namespace std;

long long int longestSubarry(long long int *arr, long long int n);

// Driver code
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << longestSubarry(arr, n) << endl;
    }
    return 0;
}

// } Driver Code Ends


long long int longestSubarry(long long int a[], long long int n) {
    int mx=0;
    int len=0;
    for(int i=0;i<n;i++)
    {
        if(a[i]>=0)
        {
            len++;
        }
        else
        {
            mx=max(mx,len);
            len=0;
        }
    }
    mx=max(mx,len);
    return mx;
}