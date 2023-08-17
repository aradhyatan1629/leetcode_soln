class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int cnt1=0,cnt2=0;
        int element1,element2;
        
        for(int i=0;i<nums.size();i++)
        {
            if(cnt1==0 and element2!=nums[i])
            {
                cnt1=1;
                element1 = nums[i];
            }
            else if(cnt2==0 and element1!=nums[i])
            {
                cnt2=1;
                element2 = nums[i];
            }
            else if(element1 == nums[i])
            {
                cnt1++;
            }
            else if(element2 == nums[i])
            {
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        vector<int> ans;
        cnt1=0,cnt2=0;
        int t = nums.size()/3;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == element1)
            {
                cnt1++;
            }
            else if(nums[i] == element2)
            {
                cnt2++;
            }
        }
        if(cnt1>t)
        {
            ans.push_back(element1);
        }
        if(cnt2>t)
        {
            ans.push_back(element2);
        }
        return ans;
    }
};