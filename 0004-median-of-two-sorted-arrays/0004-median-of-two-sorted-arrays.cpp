class Solution {
public:
    //O(n) and O(1)
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size(),n2=nums2.size();
        int n = n1+n2;
        int ind1=(n/2)-1;
        int ind2=n/2;
        int ind1e=-1,ind2e=-1;
        int cnt=0;
        int i=0,j=0;
        
        while(i<n1 and j<n2)
        {
            if(nums1[i]<=nums2[j])
            {
                if(cnt==ind1){ind1e=nums1[i];}
                if(cnt==ind2){ind2e=nums1[i];}
                cnt++;
                i++;
            }
            else
            {
                if(cnt==ind1){ind1e=nums2[j];}
                if(cnt==ind2){ind2e=nums2[j];}
                cnt++;
                j++;
            }
        }
        while(i<n1)
        {
            if(cnt==ind1){ind1e=nums1[i];}
            if(cnt==ind2){ind2e=nums1[i];}
            cnt++;
            i++;
        }
        while(j<n2)
        {
            if(cnt==ind1){ind1e=nums2[j];}
            if(cnt==ind2){ind2e=nums2[j];}
            cnt++;
            j++;
        }
        if(n%2==1)
        {
            return (double)ind2e;
        }
        return double((double(ind1e+ind2e))/2.0);
    }
};