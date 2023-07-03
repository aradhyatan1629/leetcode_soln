class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s==goal)
        {
            unordered_set<char> st(s.begin(),s.end());
            return st.size()<s.size();
        }
        int n=s.size();
        int l=0,r=n-1;
        while(l<n and s[l]==goal[l])
        {
            l++;
        }
        while(r>=0 and s[r]==goal[r])
        {
            r--;
        }
        if(l<r)
        {
            swap(s[l],s[r]);
        }
        return s==goal;
    }
};