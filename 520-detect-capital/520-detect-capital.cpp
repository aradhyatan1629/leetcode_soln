class Solution {
public:
    bool detectCapitalUse(string word) {
        int cap=0,low=0;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>=65 and word[i]<=90)
            {
                cap++;
            }
            else
            {
                low++;
            }
        }
        if(cap!=0 and low==0)
        {
            return true;
        }
        if(low!=0 and cap==0)
        {
            return true;
        }
        if(cap==1 and ((word[0])>=65 and word[0]<=90))
        {
            return true;
        }
        return false;
    }
};