class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        int n = num.size();
        int i=0;
        
        while(i<n)
        {
            while(k>0 and (!st.empty() and num[i]-'0' < st.top()))
                k--,st.pop();
            st.push(num[i]-'0');
            i++;
        }
        if(k)
        {
            while(k)
                st.pop(),k--;
        }
        
        stack<int> st1;
        while(!st.empty())
            st1.push(st.top()),st.pop();
        while(!st1.empty() and st1.top()==0)
            st1.pop();
        if(st1.empty())
            return "0";
        
        string ans;
        while(!st1.empty())
        {
            ans += char(st1.top()+'0');
            st1.pop();
        }
        
        return ans;
    }
};