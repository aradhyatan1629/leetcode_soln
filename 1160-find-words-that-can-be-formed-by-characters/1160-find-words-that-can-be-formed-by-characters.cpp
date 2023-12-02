class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int res=1;
        int ans=0;
        for(auto w:words)
        {
            for(auto c:w)
            {
                if(count(w.begin(),w.end(),c)>count(chars.begin(),chars.end(),c))
                {
                    res=0;
                    break;
                }
            }
            if(res==1)
            {
                ans=ans+w.size();
            }
            res=1;
        }
        return ans;
    }
};