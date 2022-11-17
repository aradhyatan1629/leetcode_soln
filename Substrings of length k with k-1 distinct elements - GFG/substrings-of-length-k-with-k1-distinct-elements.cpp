//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        int i=0,j=0,n=s.size();
        unordered_set<char> st;
        unordered_map<char,int> m;
        int cnt=0;
        while(j<n)
        {
            st.insert(s[j]);
            m[s[j]]++;
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                // for(auto x:st)
                // {
                //     cout<<x<<" ";
                // }
                // cout<<endl;
                m[s[i]]--;
                if(st.size()==k-1)
                {
                    cnt++;
                }
                if(m[s[i]]==0)
                {
                    st.erase(s[i]);
                }
                i++;
                j++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    }
    return 0;
}
// } Driver Code Ends