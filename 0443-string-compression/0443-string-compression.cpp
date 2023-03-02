class Solution {
public:
    int compress(vector<char>& chars) {
        char prev=chars[0];
        int cnt=0;
        string s;
        for(int i=0;i<chars.size();i++)
        {
            if(chars[i]==prev)
            {
                cnt++;
            }
            else if(cnt==1)
            {
                s+=prev;
                prev=chars[i];
                cnt=1;
            }
            else
            {
                s+=prev;
                s+=to_string(cnt);
                prev=chars[i];
                cnt=1;
            }
        }
        s+=prev;
        if(cnt!=1)
        {
            s+=to_string(cnt);
        }
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            chars[j]=s[i];
            j++;
        }
        return s.size();
    }
};