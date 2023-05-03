class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans;
        unordered_set<int> st1(nums1.begin(),nums1.end());
        unordered_set<int> st2(nums2.begin(),nums2.end());
        vector<int> v;
        for(auto x:st1)
        {
            if(st2.find(x)==st2.end())
            {
                v.push_back(x);
            }
        }
        ans.push_back(v);
        v.clear();
        for(auto x:st2)
        {
            if(st1.find(x)==st1.end())
            {
                v.push_back(x);
            }
        }
        ans.push_back(v);
        return ans;
    }
};