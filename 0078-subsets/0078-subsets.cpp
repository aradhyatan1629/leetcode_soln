class Solution {
public:
    vector<vector<int>> ans;
    void f(int ind,vector<int> &sub,vector<int> &nums,int n)
    {
        if(ind>=n)
        {
           ans.push_back(sub);
           return;
        }
        sub.push_back(nums[ind]);//adding the givenarray(nums) element in our subsequence array
        f(ind+1,sub,nums,n); //take
        sub.pop_back(); //bringing the array to the state it was in
        f(ind+1,sub,nums,n);//not take
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> sub;
        int n=nums.size();
        f(0,sub,nums,n);
        return ans;
    }
};