class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> m;
        for(auto x:text)
        {
            m[x]++;
        }
        int cnt=0;
        while(true)
        {
            if(m['b']>=1 && m['a']>=1 && m['l']>=2 && m['o']>=2 && m['n']>=1)
            {
                cnt++;
                m['b']-=1;
                m['a']-=1;
                m['l']-=2;
                m['o']-=2;
                m['n']-=1;
            }
            else
            {
                break;
            }
        }
        return cnt;
    }
};