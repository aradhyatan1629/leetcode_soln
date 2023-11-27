class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1=0,cnt1=0,sum2=0,cnt2=0;
        
        for(int i=0;i<nums1.size();i++)
        {
            if(nums1[i]==0)
                cnt1++;
            else
                sum1 += (long long)(nums1[i]);
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(nums2[i]==0)
                cnt2++;
            else
            {
                sum2 += (long long)(nums2[i]);
            }
        }
        // sum1 = accumulate(nums1.begin(),nums1.end(),0);
        // sum2 = accumulate(nums2.begin(),nums2.end(),0);
        // cnt1 = count(nums1.begin(),nums1.end(),0);
        // cnt2 = count(nums2.begin(),nums2.end(),0);
        
//         cout<<cnt1<<" "<<sum1<<endl;
//         cout<<cnt2<<" "<<sum2<<endl;
        
        if(cnt1==0 or cnt2==0)
        {
            if(cnt1==0 and cnt2==0 and sum1!=sum2){return -1;}
            if(cnt1==0 and cnt2==0 and sum1==sum2){return sum1;}
            if(cnt1==0 and cnt2!=0 and sum1 < (long long)(sum2 + cnt2)){return -1;}
            if(cnt2==0 and cnt1!=0 and (long long)(sum1 + cnt1) > sum2){return -1;}
        }
        if(cnt1==cnt2)
        {
            long long mx = max(sum1,sum2);
            return (long long)(mx+cnt1);
        }
        
        long long ans = max((long long)(sum1+cnt1),(long long)(sum2+cnt2));
        return ans;
    }
};