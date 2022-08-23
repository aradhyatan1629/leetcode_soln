class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> ans;
        int cnt=0;
        for(int i=0;i<queries.size();i++)
        {
            int cnt=0;
            int x1=queries[i][0];
            int y1=queries[i][1];
            int r=queries[i][2];
            for(int j=0;j<points.size();j++)
            {
                int x2=points[j][0];
                int y2=points[j][1];
                int d = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                if(d<=r*r)
                {
                    cnt++;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};