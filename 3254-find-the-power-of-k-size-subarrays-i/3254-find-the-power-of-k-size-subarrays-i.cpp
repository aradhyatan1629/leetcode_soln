class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int i=0,j=0,n=nums.size();
        
        vector<int> ans;
        int ind = -1;
        while(i<=n-k && j<n){
            // cout<<i<<" "<<j<<endl;
            if(j-i+1 < k){
                if(nums[j]>=nums[j+1] || nums[j+1]-nums[j]!=1)
                    ind = j;
                j++;
            }
            else if(j-i+1 == k){
                if(ind < i){
                    ans.push_back(nums[j]);
                    i++;
                    // if(k == 1)j++;
                }
                else{
                    while(i<=n-k && i<=ind){
                        ans.push_back(-1);
                        i++;
                    }
                }
            }
        }
        return ans;
    }
};

/*

n = 7
1,2,3,4,3,2,5








*/