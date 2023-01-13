class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_set<string> st;
        unordered_map<char,string> m;
        string word;
        int j=0;
        int cnt1=pattern.size();
        int cnt2=count(s.begin(),s.end(),' ')+1;
        if(cnt1!=cnt2)
        {
            return false;
        }
        if(pattern.size()==1 and s.size()==1)
        {
            return true;
        }
        if(pattern.size()>1 and s.size()>1 and pattern==s )
        {
            return false;
        }
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(m[pattern[j]]=="" and st.find(word)==st.end())
                {
                    m[pattern[j]]=word;
                }
                else if(m[pattern[j]]=="" and st.find(word)!=st.end())
                {
                    return false;
                }
                else if(m[pattern[j]]!=word)
                {
                    return false;
                }
                j++;
                st.insert(word);
                word.clear();
            }
            else
            {
                word+=s[i];
            }
        }
        if(m[pattern[j]]=="" and st.find(word)==st.end())
        {
            m[pattern[j]]=word;
        }
        else if(m[pattern[j]]=="" and st.find(word)!=st.end())
        {
            return false;
        }
        else if(m[pattern[j]]!=word)
        {
            return false;
        }
        return true;
    }
};