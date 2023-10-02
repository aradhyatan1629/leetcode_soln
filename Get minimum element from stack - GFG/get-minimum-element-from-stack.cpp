//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> st1,st2;
    public:
    
       int getMin(){
           if(st2.empty())
           {
               return -1;
           }
           return st2.top();
       }
       
       int pop(){
           if(st1.empty())
           {
               return -1;
           }
           if(st1.top() == st2.top())
           {
               st2.pop();
           }
           int x = st1.top();
           st1.pop();
           return x;
       }
       
       void push(int x){
           st1.push(x);
           if(st2.empty() or x<=st2.top())
           {
               st2.push(x);
           }
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends