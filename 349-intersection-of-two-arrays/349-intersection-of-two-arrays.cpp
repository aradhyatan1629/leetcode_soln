class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        unordered_set<int> s;
        for(auto x:nums1)
        {
            m1[x]++;
        }
        for(auto x:nums2)
        {
            m2[x]++;
        }
        for(auto x:nums1)
        {
            if(m1[x]>0 and m2[x]>0)
            {
                s.insert(x);
            }
        }
        vector<int> v(s.begin(),s.end());
        return v;
    }
};