//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) {
        if(n==1)
        {
            return 1;
        }
        int leftSum = 0,totalSum=0,ans=-1;
        for(int i=0;i<n;i++)
        {
            totalSum+=a[i];
        }
        for(int i=0;i<n;i++)
        {
            if(leftSum == totalSum-(leftSum+a[i]))
            {
                ans = i+1;
                break;
            }
            else
            {
                leftSum+=a[i];
            }
        }
        return ans;
    }

};






//{ Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}

// } Driver Code Ends