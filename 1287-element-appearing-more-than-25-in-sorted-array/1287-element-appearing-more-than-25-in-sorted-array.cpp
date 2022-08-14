class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        unordered_map<int,int> m;
        int n = arr.size();
        for(auto x:arr)
        {
            m[x]++;
        }
        double p = 0;
        for(auto x:m)
        {
            if(x.second>arr.size()/4)
            {
                return x.first;
            }
        }
        return 0;
    }
};