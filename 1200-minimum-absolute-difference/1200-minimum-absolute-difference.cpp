class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int mn = INT_MAX;
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=1;i<arr.size();i++)
        {
            int diff = abs(arr[i]-arr[i-1]);
            if(diff<mn)
            {
                mn = diff;
            }
        }
        for(int i=1;i<arr.size();i++)
        {
            int diff = abs(arr[i]-arr[i-1]);
            vector<int> v;
            if(diff==mn)
            {
                v.push_back(arr[i-1]);
                v.push_back(arr[i]);
                ans.push_back(v);
            }
        }
        return ans;
    }
};

    
// -14 -10 -4 3 8 19 23 27