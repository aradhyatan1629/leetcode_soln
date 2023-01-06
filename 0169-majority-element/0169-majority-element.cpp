class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //O(n) O(1) Moore Voting Algo
        int cnt=0,element=0;
        for(int i=0;i<nums.size();i++)
        {
            if(cnt==0)
            {
                element=nums[i];
            }
            if(element==nums[i])
            {
                cnt++;
            }
            else
            {
                cnt-=1;
            }
        }
        return element;
    }
};

