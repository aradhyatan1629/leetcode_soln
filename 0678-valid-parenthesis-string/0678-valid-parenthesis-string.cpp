class Solution {
public:
    bool checkValidString(string s) {
        stack<int> st1,st2;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
                st1.push(i);
            else if(s[i]=='*')
                st2.push(i);
            else if(s[i]==')')
            {
                if(st1.empty() and st2.empty())
                    return false;
                else if(!st1.empty())
                    st1.pop();
                else
                    st2.pop();
            }
        }
        while(!st1.empty())
        {
            if(st2.empty())return false;
            if(st1.top() > st2.top())return false;
            st1.pop();
            st2.pop();
        }
        return true;
    }
};