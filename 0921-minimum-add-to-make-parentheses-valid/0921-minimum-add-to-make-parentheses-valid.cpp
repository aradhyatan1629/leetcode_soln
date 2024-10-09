class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.size() == 0)
            return 0;
        
        stack<char> st;
        int i = 0;
        while(i<s.size()){
            while(i<s.size() && !st.empty() && (st.top() == '(' && s[i] == ')')){
                st.pop();
                i++;
            }
            if(i<s.size()){
                st.push(s[i]);
                i++;
            }
        }
        return st.size();
    }
};