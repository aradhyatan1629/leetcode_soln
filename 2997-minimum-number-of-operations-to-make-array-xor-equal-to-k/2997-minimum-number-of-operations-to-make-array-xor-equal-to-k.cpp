class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int r = 0;
        int cnt = 0;
        for(int i=0;i<nums.size();i++)
            r^=nums[i];
        
        while(r!=0 || k!=0)
        {
            int bit1 = r&1;
            int bit2 = k&1;
            if(bit1 != bit2)
                cnt++;
            r = r>>1;
            k = k>>1;
        }
        return cnt;
    }
};