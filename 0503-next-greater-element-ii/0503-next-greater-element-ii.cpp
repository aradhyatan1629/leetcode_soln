class Solution {
public:
    //O(n^2)
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<n;i++)
        {
            bool found=false;
            for(int j=i+1;j<i+n;j++)
            {
                int index=j%n;
                if(nums[index]>nums[i])
                {
                    found=true;
                    ans.push_back(nums[index]);
                    break;
                }
            }
            if(!found)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};