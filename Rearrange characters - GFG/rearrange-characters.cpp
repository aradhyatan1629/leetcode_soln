//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

// } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        priority_queue<pair<int,char>> pq;
        unordered_map<char,int> m;
        for(int i=0;i<str.size();i++)
        {
            m[str[i]]++;
        }
        for(auto x:m)
        {
            pq.push({x.second,x.first});
        }
        
        string ans;
        while(pq.size()>1)
        {
           auto top1 = pq.top();
           pq.pop();
           auto top2 = pq.top();
           pq.pop();
           
           ans+=top1.second;
           ans+=top2.second;
           
           top1.first--;
           top2.first--;
           
           if(top1.first>0)
           {
               pq.push({top1});
           }
           if(top2.first>0)
           {
               pq.push({top2});
           }
        }
        if(!pq.empty())
        {
            if(pq.top().first>1)
            {
                return "-1";
            }
            ans+=pq.top().second;
        }
        return ans;
    }
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}
// } Driver Code Ends