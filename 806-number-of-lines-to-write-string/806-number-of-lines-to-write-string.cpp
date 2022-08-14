class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int line=1;
        int wth=0;
        for(int i=0;i<s.size();i++)
        {
             wth+=widths[s[i]-'a'];
            if(wth>100)
            {
                wth=widths[s[i]-'a'];
                line++;
            }
        }
        vector<int> ans;
        ans.push_back(line);
        ans.push_back(wth);
        return ans;
    }
};