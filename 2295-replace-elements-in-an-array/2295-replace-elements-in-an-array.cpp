class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int,int> m;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }
        for(int i=0;i<operations.size();i++)
        {
            int temp = m[operations[i][0]];
            nums[temp]=operations[i][1];
            m.erase(operations[i][0]);
            m[operations[i][1]]=temp;
        }
        return nums;
    }
};