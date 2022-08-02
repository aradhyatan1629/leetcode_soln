class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        unordered_set<int> s;
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        unordered_map<int,int> m3;
        for(auto x:nums1)
        {
            m1[x]++;
        }for(auto x:nums2)
        {
            m2[x]++;
        }
        for(auto x:nums3)
        {
            m3[x]++;
        }
        for(int i=0;i<nums1.size();i++)
        {
            if(s.find(nums1[i])!=s.end())
            {
                continue;
            }
            if(m2[nums1[i]]>0 or m3[nums1[i]]>0)
            {
                s.insert(nums1[i]);
            }
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(s.find(nums2[i])!=s.end())
            {
                continue;
            }
            if(m1[nums2[i]]>0 or m3[nums2[i]]>0)
            {
                s.insert(nums2[i]);
            }
        }
        for(int i=0;i<nums3.size();i++)
        {
            if(s.find(nums3[i])!=s.end())
            {
                continue;
            }
            if(m1[nums3[i]]>0 or m2[nums3[i]]>0)
            {
                s.insert(nums3[i]);
            }
        }
        vector<int> v(s.begin(),s.end());
        return v;
    }
};