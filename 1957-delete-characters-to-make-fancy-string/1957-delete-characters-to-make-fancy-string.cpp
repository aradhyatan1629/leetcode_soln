class Solution {
public:
    string makeFancyString(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++){
            if(st.size() >= 2 && st.top() == s[i]){
                char top1 = st.top();st.pop();
                char top2 = st.top();st.pop();
                bool flag = false;
                if(top1 != s[i] || top2 != s[i]){
                    flag = true;
                }
                st.push(top2);
                st.push(top1);
                if(flag)st.push(s[i]);
            }
            else{
                st.push(s[i]);
            }
        }
        string ans;
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};