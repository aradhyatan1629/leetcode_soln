class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        int cnt=0;
        while(s!=goal)
        {
            char first = s[0];
            for(int i=0;i<s.size()-1;i++)
            {
                s[i]=s[i+1];
            }
            s[n-1] = first;
            first = s[0];
            cnt++;
            if(cnt==n and s!=goal)
            {
                return false;
            }
        }
        return true;
    }
};