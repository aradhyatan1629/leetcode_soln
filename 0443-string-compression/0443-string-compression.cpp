class Solution {
public:
    int compress(vector<char>& chars) {
        char prev=chars[0];
        int cnt=0;
        int j=0;
        for(int i=0;i<chars.size();i++)
        {
            if(chars[i]==prev)
            {
                cnt++;
            }
            else if(cnt==1)
            {
                chars[j++]=prev;
                prev=chars[i];
                cnt=1;
            }
            else
            {
                chars[j++]=prev;
                string s = to_string(cnt);
                for(char x:s)
                {
                    chars[j++] = x;
                }
                prev=chars[i];
                cnt=1;
            }
        }
        chars[j++]=prev;
        if(cnt!=1)
        {
            string s = to_string(cnt);
            for(char x:s)
            {
                chars[j++] = x;
            }
        }
        return j;
    }
};