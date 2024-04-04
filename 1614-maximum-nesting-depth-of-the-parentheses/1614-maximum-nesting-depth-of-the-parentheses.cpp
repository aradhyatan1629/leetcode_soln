class Solution {
public:
    int maxDepth(string s) {
        int mx = 0;
        int l = 0;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '(')
            {
                l++;
                mx = max(mx,l);
            }
            else if(s[i]==')')
            {
                l--;
            }
        }
        return mx;
    }
};