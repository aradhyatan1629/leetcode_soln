class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> v;
        
        for(int i = 0; i < timePoints.size(); i++) {
            int h = (timePoints[i][0] - '0') * 10 + (timePoints[i][1] - '0');
            int m = (timePoints[i][3] - '0') * 10 + (timePoints[i][4] - '0');
            v.push_back(h * 60 + m);
        }
        
        sort(v.begin(), v.end());
        
        int mn = INT_MAX;
        for(int i = 0; i < v.size() - 1; i++) {
            mn = min(mn, v[i + 1] - v[i]);
        }
        int circularDiff = 1440 - v.back() + v[0];  
        mn = min(mn, circularDiff);
        
        return mn;
    }
};
