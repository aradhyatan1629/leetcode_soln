class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(int i=0;i<knowledge.size();++i)
        {
            m[knowledge[i][0]] = knowledge[i][1];
        }
        string ans;
        string word;
        for(int i=0;i<s.size();++i)
        {
            if(s[i]=='(')
            {
                while(s[i+1]!=')')
                {
                    word+=s[i+1];
                    i++;
                }
                i++;
                if(m[word]=="")
                {
                    ans+='?';
                }
                else
                {
                    ans+=m[word];
                }
                word.clear();
            }
            else
            {
                ans+=s[i];
            }
        }
        return ans;
    }
};