class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<int> v;
        int n = nums.size();
        int j=0,i=0;
        int mn = INT_MAX,mx=INT_MIN;
        while(j<n)
        {
            mn = nums[i];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                mx=nums[j];
                v.push_back(mx-mn);
                i++;
                j++;
            }   
        }
        return *min_element(v.begin(),v.end());
    }
};

// 1 4 7 9