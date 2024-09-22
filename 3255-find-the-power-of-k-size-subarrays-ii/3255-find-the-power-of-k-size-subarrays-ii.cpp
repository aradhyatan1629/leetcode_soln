class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int i=0,j=0,n=nums.size();
        // bool flag = true;
        int ind = -1;
        
        while(j<n){
            if(j>0 && (nums[j]-nums[j-1])!=1){
                ind = j;
            }
            if(j-i+1 < k){
                j++;
            }
            else if(j-i+1 == k){
                if(i>=ind)
                    ans.push_back(nums[j]);
                else
                    ans.push_back(-1);
                i++,j++;
            }
        }
        return ans;
    }
};


/*
1,2,3,4,3,2,5



*/




