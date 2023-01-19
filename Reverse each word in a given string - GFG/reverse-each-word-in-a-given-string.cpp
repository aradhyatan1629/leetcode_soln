//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseWords (string s)
    {
        string word;
        string ans;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=97 and s[i]<=122 or s[i]>=65 and s[i]<=91 or s[i]>=48 and s[i]<=57)
            {
                word+=s[i];
            }
            else
            {
                reverse(word.begin(),word.end());
                ans+=word;
                ans+=s[i];
                word.clear();
            }
        }
        reverse(word.begin(),word.end());
        ans+=word;
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.reverseWords (s) << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends