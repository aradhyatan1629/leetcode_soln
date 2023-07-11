class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        
        int ans = 0;
        int i=0;
        while(i<s.size())
        {
            if(s[i]=='I')
            {
                if(i<s.size()-1 and (s[i+1]=='V' or s[i+1]=='X'))
                {
                    ans+=(m[s[i+1]]-m[s[i]]);
                    i++;
                }
                else
                {
                    ans+=m[s[i]];
                }
            }
            else if(s[i]=='X')
            {
                if(i<s.size()-1 and (s[i+1]=='L' or s[i+1]=='C'))
                {
                    ans+=(m[s[i+1]]-m[s[i]]);
                    i++;
                }
                else
                {
                    ans+=m[s[i]];
                }
            }
            else if(s[i]=='C')
            {
                if(i<s.size()-1 and (s[i+1]=='D' or s[i+1]=='M'))
                {
                    ans+=(m[s[i+1]]-m[s[i]]);
                    i++;
                }
                else
                {
                    ans+=m[s[i]];
                }
            }
            else
            {
                ans+=m[s[i]];
            }
            i++;
        }
        return ans;
        
    }
};