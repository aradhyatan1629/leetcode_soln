//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSubstring(string s) {
        unordered_map<char,int> m;
        int i=0,j=0,n=s.size();
        int ans=0;
        while(j<n)
        {
            m[s[j]]++;
            if(m.size()<3)
            {
                j++;
            }
            else
            {
                while(i<n and m.size()==3)
                {
                    ans += (n-j);
                    m[s[i]]--;
                    if(m[s[i]]==0){m.erase(s[i]);}
                    i++;
                }
                j++;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution obj;
        cout << obj.countSubstring(s) << endl;
    }
    return 0;
}
// } Driver Code Ends