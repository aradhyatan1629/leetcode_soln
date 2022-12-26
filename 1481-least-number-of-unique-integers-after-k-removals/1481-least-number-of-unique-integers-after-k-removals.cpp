class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        vector<pair<int,int>> v;
        for(auto x:arr)
        {
            m[x]++;
        }
        for(auto x:m)
        {
            v.push_back({x.second,x.first});
        }
        sort(v.begin(),v.end());
        int cnt=0;
        for(auto x:v)
        {
            if(k>=x.first)
            {
                cnt++;
                k-=x.first;
            }
        }
        return v.size()-cnt;
    }
};
/*
1 - 2
2 - 1
3 - 3
4 - 1
*/

// (1,2)
// (2,1)
// (3,3)