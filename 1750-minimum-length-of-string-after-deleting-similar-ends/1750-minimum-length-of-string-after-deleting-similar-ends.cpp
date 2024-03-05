class Solution {
public:
    int minimumLength(string s) {
        int n=s.size();
        int i=0,j=n-1;
        bool pre=false,suff=false;
        while(i<j)
        {
            if(s[i]!=s[j])
            {
                break;
            }
            else
            {
                char ch = s[i];//i++,j--;
                while(i<j and s[i]==ch)i++;
                while(i<j and s[j]==ch)j--;
                // cout<<i<<" "<<j<<endl;
            }
        }
        // cout<<i<<" "<<j<<endl;
        // if(j<i)return 0;
        if(j==i and ((i>0 and j<n-1) and (s[i-1] == s[j+1])))return 1;
        if(j==i and (i>0 and s[i-1]==s[j]))return 0;
        
        return j-i+1;
    }
};