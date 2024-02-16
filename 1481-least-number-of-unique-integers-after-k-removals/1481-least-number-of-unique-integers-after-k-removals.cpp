class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto x:arr)
            m[x]++;
        vector<pair<int,int>> v;
        for(auto x:m)
            v.push_back({x.second,x.first});
        sort(v.begin(),v.end());
        int cnt=m.size();
        for(auto x:v)
        {
            if(x.first>k)
                break;
            cnt--;
            k-=x.first;
        }
        return cnt;
    }
};