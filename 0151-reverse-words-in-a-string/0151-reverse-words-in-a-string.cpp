class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ' and word!="")
            {
                st.push(word);
                word.clear();
            }
            else if(s[i]!=' ')
            {
                word+=s[i];
            }
        }
        if(word!="")
        {
            st.push(word);
            word.clear();
        }
        while(!st.empty())
        {
            word+=st.top();
            word+=" ";
            st.pop();
        }
        word.erase(word.end()-1);
        return word;
    }
};