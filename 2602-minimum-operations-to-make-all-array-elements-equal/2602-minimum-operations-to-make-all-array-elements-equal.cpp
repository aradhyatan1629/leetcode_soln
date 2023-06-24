class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        vector<long long> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        
        vector<long long> pre(n+1);
        pre[0] = 0;
        for(int i=1;i<pre.size();i++)
        {
            pre[i] = pre[i-1] + nums[i-1];
        }
        for(long long q:queries)
        {
            auto it = upper_bound(nums.begin(),nums.end(),q);
            int index = it-nums.begin();
            long long left = index*q - pre[index];
            long long right = (pre[n] - pre[index]) - (n-index)*q;
            ans.push_back(left + right);
        }
        return ans;
    }
};


/*

If the array is sorted say 1 3 5 8 9 
and the given query is 5
then 5 SPLITS the array into two parts 
one is all elements smaller than 5 and other is all elements larger than 5
so for both the parts we can use prefix sum concept to get the answer
*/