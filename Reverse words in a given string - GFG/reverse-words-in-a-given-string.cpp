//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        stack<string> st;
        string word;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='.')
            {
                st.push(word);
                st.push(".");
                word.clear();
            }
            else
            {
                word+=s[i];
            }
        }
        st.push(word);
        word.clear();
        while(!st.empty())
        {
            word+=st.top();
            st.pop();
        }
        return word;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends