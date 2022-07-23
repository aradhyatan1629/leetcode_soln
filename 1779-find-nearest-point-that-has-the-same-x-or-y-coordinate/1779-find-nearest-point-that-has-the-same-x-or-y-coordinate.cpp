class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        int i=0;
        int temp=0;
        int dist = INT_MAX;
        int m = points.size();
        int tx = INT_MAX;
        for(i=0;i<m;++i)
        {
            int x1 = points[i][0];
            int y1 = points[i][1];
            if(x1==x || y1==y)
            {
                temp = abs(x-x1) + abs(y-y1);
                if(temp<dist)
                {
                    dist = temp;
                    tx = i;
                }
            }
        }
        if(dist==INT_MAX)
        {
            return -1;
        }
        return tx;
    }
};