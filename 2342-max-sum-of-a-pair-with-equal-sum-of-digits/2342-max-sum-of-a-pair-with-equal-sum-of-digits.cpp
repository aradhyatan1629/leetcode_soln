class Solution {
public:
    int maximumSum(vector<int>& nums) {
        
        unordered_map<int,multiset<int>> m;     
        
        for(int i=0;i<nums.size();i++)
        {
            int n = nums[i];
            int sum = 0;
            while(n)
            {
                sum += (n%10);
                n/=10;
            }
            m[sum].insert(nums[i]);
        }
        
        int mx = -1;
        for(auto x:m)
        {
            if(x.second.size()>=2)
            {
                auto it = x.second.end();
                it--; 
                int lastElement = *it;
                it--;
                int secondLastElement = *it;
                mx = max(mx, (lastElement + secondLastElement));
            }
        }
        return mx;
        
    }
};