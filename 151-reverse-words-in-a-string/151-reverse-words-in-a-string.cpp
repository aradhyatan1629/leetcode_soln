class Solution {
public:
    string reverseWords(string s) {
        vector<string> v;
        string word;
        for(int i=0;i<s.size();i++)
        {
            if((s[i]>=65 and s[i]<=90) or (s[i]>=97 and s[i]<=122) or (s[i]>=48 and s[i]<=57))
            {
                word+=s[i];
            }
            if(s[i]==' ' and word!="")
            {
                v.push_back(word);
                word.clear();
            }
        }
        if(word!="")
        {
            v.push_back(word);
        }
        word.clear();
        for(int i=v.size()-1;i>0;i--)
        {
            word+=v[i];
            word+=" ";
        }
        word+=v[0];
        return word;
    }
};