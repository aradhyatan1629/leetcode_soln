class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int j=0;
        int n = s.size();
        vector<string> ans;
        string r;
        while(j<n)
        {
            r+=s[j];
            if(r.size()==k)
            {
                ans.push_back(r);
                r="";
            }
            j++;
        }
        if(r!="")
        {
            while(r.size()!=k)
            {
                r+=fill;
            }
            ans.push_back(r);
        }
        return ans;
    }
};