class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int cnt=0;
        if(maxDoubles==0)
        {
            return target-1;
        }
        int current=target;
        while(current!=1)
        {
            if(current%2==0 and maxDoubles>0)
            {
                current=current/2;
                cnt++;
                maxDoubles--;
            }
            else if(current%2==1  and maxDoubles>0)
            {
                current--;
                cnt++;
            }
            if(maxDoubles==0)
            {
                break;
            }
        }
        if(current!=1)
        {
            cnt+=current-1;
        }
        return cnt;
    }
};