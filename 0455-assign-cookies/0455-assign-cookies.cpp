class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int i=0,j=0;
        while(i<g.size() and j<s.size())
        {
            if(g[i]>s[j])
                j++;
            else if(g[i]<=s[j])
                i++,j++;
        }
        return i;
    }
};