class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<int> st;
        for(int i=0;i<num.size();i++)
        {
            while(k>0 and (!st.empty() and st.top()>num[i]-'0'))
            {
                st.pop();
                k--;
            }
            st.push(num[i]-'0');
        }
        if(k)
        {
            while(k)
            {
                st.pop();k--;
            }
        }
        num="";
        while(!st.empty())
        {
            num += char(st.top()+'0');
            st.pop();   
        }
        reverse(num.begin(),num.end());
        int i=0;
        for(;i<num.size();i++)
        {
            if(num[i]!='0')
                break;
        }
        if(num=="" or i>=num.size())return "0";
        return num.substr(i,num.size()-i);
    }
};