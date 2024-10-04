class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size()<2)
            return false;
        
        unordered_map<int,int> m; // {remainder,index}
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            int rem = sum%k;
            if(rem == 0 && i>0)
                return true;
            if(m.find(rem) != m.end() && i-m[rem]>=2)
                return true;
            if(m.find(rem) == m.end())
                m[rem] = i;
        }
        return false;
    }
};


/*

2,2,3,3 k = 3



*/