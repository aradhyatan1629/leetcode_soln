class Solution {
public:
    string reverseWords(string s) {
        string ans;
        vector<string> v;
        string temp;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]>=65 and s[i]<=91 or s[i]>=97 and s[i]<=122 or s[i]>=48 and s[i]<=57)
            {
                temp+=s[i];
            }
            else if(s[i]==' ' and temp.size()!=0)
            {
                v.push_back(temp);
                temp.clear();
            }
        }
        if(temp.size()!=0)
        {
            v.push_back(temp);
            temp.clear();
        }
        for(int i=v.size()-1;i>=0;i--)
        {
            ans+=v[i];
            ans+=" ";
        }
        ans.erase(ans.end()-1);
        return ans;
    }
};