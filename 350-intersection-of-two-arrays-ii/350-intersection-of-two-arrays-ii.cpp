class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> ans;
        for(auto x:nums1)
        {
            m1[x]++;
        }
        for(auto x:nums2)
        {
            m2[x]++;
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(m1[nums1[i]]>0 and m2[nums1[i]]>0)
            {
                int mn = min(m1[nums1[i]],m2[nums1[i]]);
                while(mn--)
                {
                    ans.push_back(nums1[i]);
                }
            }
            m1.erase(nums1[i]);
        }
        return ans;
    }
};