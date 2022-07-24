class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int i=0;
        vector<int> even;
        vector<int> odd;
        for(i=0;i<nums.size();i+=2)
        {
            even.push_back(nums[i]);
        }
        for(i=1;i<nums.size();i+=2)
        {
            odd.push_back(nums[i]);
        }
        sort(even.begin(),even.end());
        sort(odd.begin(),odd.end(),greater<int>());
        vector<int> ans(nums.size(),0);
        int j=0;
        for(i=0;i<even.size();i++)
        {
            ans[j]=even[i];
            j+=2;
        }
        j=1;
        for(i=0;i<odd.size();i++)
        {
            ans[j]=odd[i];
            j+=2;
        }
        return ans;
    }
};