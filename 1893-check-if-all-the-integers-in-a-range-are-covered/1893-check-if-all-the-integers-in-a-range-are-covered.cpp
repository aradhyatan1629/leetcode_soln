class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for(int i=left;i<=right;i++)
        {
            int flag=1;
            for(int j=0;j<ranges.size();j++)
            {
                int x = ranges[j][0];
                int y = ranges[j][1];
                if(i>=x && i<=y)
                {
                    flag=1;
                    break;
                }
                else
                {
                    flag=-1;
                }
            }
            if(flag==-1)
            {
                return false;
            }
        }
        return true;
    }
};