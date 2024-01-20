class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for(int i=0;i<n;i++)
        {
            while(k>0 and (!st.empty() and st.top() > num[i]))
            {
                st.pop();k--;
            }
            st.push(num[i]);
        }
        if(k>0)   // a case such as 12345
        {
            while(k!=0)
            {
                st.pop(); k--;
            }
        }
        stack<int> temp;
        while(!st.empty()){temp.push(st.top());st.pop();} 
        while(!temp.empty() and temp.top()=='0'){temp.pop();}//removing the leading zeroes
        string ans="";
        while(!temp.empty()){ans+=temp.top();temp.pop();};
        return ans = (ans=="")?"0":ans;
    }
};
