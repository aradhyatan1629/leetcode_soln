class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int xdist = abs(sx-fx);
        int ydist = abs(sy-fy);
        int mndist = min(xdist,ydist) + abs(ydist-xdist);
        if(mndist==0)
        {
            if(t==1)
                return false;
            else 
                return true;
        }
        return t>=mndist;
    }
};