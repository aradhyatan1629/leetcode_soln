class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        
        if(tokens.size()==0 or power<tokens[0]){return 0;}
        if(tokens.size()==1 and power>=tokens[0]){return 1;}
        
        int score=0;
        int i=0;
        int j=tokens.size()-1;
        while(i<j)
        {
            if(tokens[i]<=power)
            {
                power-=tokens[i];
                score++;
                i++;
            }
            else
            {
                if(i!=j)
                {
                     power+=tokens[j];
                     score--;
                     j--;
                }
            }
        }
        if(i<tokens.size() and tokens[i]<=power){score++;}
        return score;
    }
};