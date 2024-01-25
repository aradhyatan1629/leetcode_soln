class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            int x = target-nums[i];
            if(m.find(x)!=m.end())
            {
                return {m[x],i};
            }
            m[nums[i]]=i;
        }
        return {};
    }
};

// tc - O(n) on best case 
/*
In the worst case(which rarely happens), the unordered_map takes O(N) to find an element. In that case, the time complexity will be O(N2). If we use map instead of unordered_map, the time complexity will be O(N* logN) as the map data structure takes logN time to find an element.
*/