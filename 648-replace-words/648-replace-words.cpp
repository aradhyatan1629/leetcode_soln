class Solution {
public:
    string replaceWords(vector<string>& dict, string s) {
        unordered_map<string,int> m;
        vector<string> v;
        string word;
        for(auto x:dict)
        {
            m[x]=1;
        }
        int flag=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==' ')
            {
                if(flag==-1)
                {
                    v.push_back(word);
                    word.clear();
                }
                else
                {
                    flag=-1;
                }
            }
            else if(m[word]==1)
            {
                flag=1;
                v.push_back(word);
                word.clear();
                while(s[i]!=' ')
                {
                    i++;
                    if(i>=s.size())
                    {
                        break;
                    }
                }
                if(i>=s.size())
                {
                    break;
                }
                i--;
            }
            else
            {
                word+=s[i];
            }
        }
        if(word!="")
        {
            v.push_back(word);
            word.clear();
        }
        for(int i=0;i<v.size()-1;i++)
        {
            word+=v[i];
            word+=" ";
        }
        word+=v[v.size()-1];
        return word;
    }
};