class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string r;
        for(int i=0;i<words.size();i++)
        {
            r+=words[i];
            if(s.substr(0,r.size())!=r)
            {
                return false;
            }
            if(r==s)
            {
                return true;
            }
        }
                if(r.size()==s.size())
        {
            return true;
        }
        return false;
    }
};