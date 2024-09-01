class Solution {
public:
    bool check(vector<int> &v,int k)
    {
        if(abs(v[0]-v[1])>k || abs(v[0]-v[2])>k || abs(v[1]-v[2])>k)return false;
        return true;
        
    }
    
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<nums.size()-2;i+=3)
        {
            vector<int> v;
            v.push_back(nums[i]);
            v.push_back(nums[i+1]);
            v.push_back(nums[i+2]);
            if(!check(v,k))
                return {};
            ans.push_back(v);
        }
        return ans;
        
    }
};


/*

1,1,3,3,4,5,7,8,9


1,5,7,10,14,15
*/