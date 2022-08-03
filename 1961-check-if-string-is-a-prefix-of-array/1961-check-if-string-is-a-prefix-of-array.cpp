class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string r="";
        for(auto w:words)
        {
            r+=w;
            if(r==s)
            {
                return true;
            }
        }
        return false;
    }
};