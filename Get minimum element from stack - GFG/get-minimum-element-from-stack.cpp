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
    
    int minEle=-1;
    stack<int> s;
    public:
    
       int getMin(){
           if(s.size()==0)
           {
               return -1;
           }
           return minEle;
       }
       
       int pop() {
    if (s.empty()) {
        return -1;
    } else {
        int topElement = s.top();
        s.pop();
        if (topElement <= minEle) {
            int prevMin = minEle;
            minEle = 2 * minEle - topElement;
            return prevMin;
        } else {
            return topElement;
        }
    }
}

       
       void push(int x){
           if(s.empty())
           {
               s.push(x);
               minEle = x;
           }
           else if(x >= minEle)
           {
               s.push(x);
           }
           else if(x < minEle)
           {
               s.push(2*x - minEle);
               minEle = x;
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