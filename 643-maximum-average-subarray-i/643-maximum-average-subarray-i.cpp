class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        double sum=0.0;
        double mx=INT_MIN;
        while(j<n)
        {
            sum+=nums[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                mx=max(mx,sum/k);
                sum=sum-nums[i];
                i++;
                j++;
            }
        }
        return mx;
    }
};