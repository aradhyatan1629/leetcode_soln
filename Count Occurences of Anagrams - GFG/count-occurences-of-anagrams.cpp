//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	int search(string pat, string txt) {
	    unordered_map<char,int> m1,m2;
	    for(int i=0;i<pat.size();i++)
	    {
	        m1[pat[i]]++;
	    }
	    int i=0,j=0,n=txt.size(),k=pat.size();
	    int ans=0;
	    while(i<n)
	    {
	        m2[txt[j]]++;
	        if(j-i+1<k)
	        {
	            j++;
	        }
	        else if(j-i+1==k)
	        {
	            if(m1.size()==m2.size())
	            {
	                int flag=1;
	                for(auto x:m1)
	                {
	                    if(m1[x.first]!=m2[x.first])
	                    {
	                        flag=-1;
	                        break;
	                    }
	                }
	                if(flag==1)
	                {
	                    ans++;
	                }
	            }
	            m2[txt[i]]--;
	            if(m2[txt[i]]==0)
	            {
	                m2.erase(txt[i]);
	            }
	            i++;
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
        string pat, txt;
        cin >> txt >> pat;
        Solution ob;
        auto ans = ob.search(pat, txt);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends