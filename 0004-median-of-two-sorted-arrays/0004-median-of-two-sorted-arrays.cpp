class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i=0,j=0;
        vector<int> v;
        while(i<nums1.size() and j<nums2.size())
        {
            if(nums1[i]<=nums2[j])
            {
                v.push_back(nums1[i]);
                i++;
            }
            else if(nums2[j]<nums1[i])
            {
                v.push_back(nums2[j]);
                j++;
            }
        }
        while(i<nums1.size())
        {
            v.push_back(nums1[i]);
            i++;
        }
        while(j<nums2.size())
        {
            v.push_back(nums2[j]);
            j++;
        }
        if(v.size()%2!=0)
        {
            return double(v[v.size()/2]);
        }
        double ans = (double(v[v.size()/2]) + double(v[v.size()/2-1]))/2;
        return ans;
    }
};