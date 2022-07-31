class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int> ans;
        for(i=0;i<nums1.size();i++)
        {
            int flag=-1;
            auto it = find(nums2.begin(),nums2.end(),nums1[i]);
            for(auto it1=it;it1!=nums2.end();it1++)
            {
                if(*it1>nums1[i])
                {
                    flag=1;
                    ans.push_back(*it1);
                    break;
                }
            }
            if(flag==-1)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};