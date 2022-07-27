class Solution {
public:
    string decodeMessage(string key, string message) {
        int i=0;
        vector<char> v;
        vector<char> al(26,'/0');
        unordered_set<char> s;
        unordered_map<char,char> m;
        for(auto x:key)
        {
            if(s.find(x)!=s.end())
            {
                continue;
            }
            if(x==' ')
            {
                continue;
            }
            else
            {
                s.insert(x);
                v.push_back(x);
            }
        }
        for(int i=0;i<al.size();i++)
        {
            al[i] = 'a'+i;
        }
        for(int i=0;i<v.size();i++)
        {
            m.insert({v[i],al[i]});
        }
        for(int i=0;i<message.size();i++)
        {
            if(message[i]==' ')
            {
                continue;
            }
            else
            {
                message[i] = m[message[i]];
            }
        }
        return message;
    }
};