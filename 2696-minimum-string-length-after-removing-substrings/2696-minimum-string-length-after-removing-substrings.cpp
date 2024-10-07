class Solution {
public:
    bool check(stack<char> &st,char ch){
        if(st.top() == 'A' && ch == 'B')
            return true;
        if(st.top() == 'C' && ch == 'D')
            return true;
        return false;
    }
    
    int minLength(string s) {
        stack<char> st;
        int i=0;
        
        while(i<s.size()){
            while(i<s.size() && !st.empty() && check(st,s[i])){
                st.pop();
                i++;
            }
            if(i == s.size())
                break;
            st.push(s[i]);
            i++;
        }
        return st.size();
    }
};