class Solution {
public:
    bool winnerOfGame(string colors) {
        if(colors.size()<=2)
        {
            return false;
        }
        
        int i=0;
        int movesA=0,movesB=0;
        while(i<colors.size())
        {
            if(colors[i]=='A')
            {
                int cntA=0;
                while(i<colors.size() and colors[i]=='A')
                {
                    cntA++;
                    i++;
                }
                if(cntA>=3)
                {
                    movesA+=(cntA-2);
                }
            }
            else
            {
                int cntB=0;
                while(i<colors.size() and colors[i]=='B')
                {
                    cntB++;
                    i++;
                }
                if(cntB>=3)
                {
                    movesB+=(cntB-2);
                }
            }
        }
        if(movesA>movesB)
        {
            return true;
        }
        return false;
    }
};


/*
AAA   3-2 = 1
AAAA  4-2 = 2
AAAAA 5-2 = 3




*/