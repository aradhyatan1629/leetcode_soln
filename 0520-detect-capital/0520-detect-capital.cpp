class Solution {
public:
    bool detectCapitalUse(string word) {
        int flagU=-1,flagL=-1;
        int cntU=0;
        for(int i=0;i<word.size();i++)
        {
            if(word[i]>=65 and word[i]<=91)
            {
                cntU++;
                flagU=1;
            }
            else
            {
                flagL=1;
            }
        }
        if((flagU==1 and flagL==-1) or (flagU==-1 and flagL==1))
        {
            return true;
        }
        if(flagU==1 and cntU==1 and word[0]>=65 and word[0]<=91)
        {
            return true;
        }
        return false;
    }
};