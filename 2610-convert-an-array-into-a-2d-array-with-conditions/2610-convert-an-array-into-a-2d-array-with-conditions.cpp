class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_set<int> st1;
        unordered_set<int> st2;
        vector<vector<int>> ans;
        while(st1.size()!=nums.size())
        {
            vector<int> v;
            for(int i=0;i<nums.size();i++)
            {
                if(st1.find(i)==st1.end() and st2.find(nums[i])==st2.end())
                {
                    v.push_back(nums[i]);
                    st1.insert(i);
                    st2.insert(nums[i]);
                }
            }
            st2.clear();
            ans.push_back(v);
        }
        return ans;
    }
};





/*
1 - 3
2 - 1
3 - 2
4 - 1
*/