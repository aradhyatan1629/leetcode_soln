class Solution {
public:
    int search(int s,int e,vector<int> &v){
        int low = 0;
        int high = v.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(v[mid] >= s && v[mid] < e)
                return true;
            else if(v[mid] >= e)
                high = mid-1;
            else
                low = mid+1;
        }
        return false;
    } 
    
    bool check(int x,int y){
        if(x%2 == 0 && y%2 == 0)
            return true;
        if(x%2 != 0 && y%2 != 0)
            return true;
        return false;
    }
    
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> v;
        int n = nums.size();
        vector<bool> ans;
        
        for(int i=0;i<n-1;i++){
            if(check(nums[i],nums[i+1])){
                v.push_back(i);
            }
        } 
        
        for(int i=0;i<queries.size();i++){
            int s = queries[i][0];
            int e = queries[i][1];
            if(s == e){
                ans.push_back(true);
                continue;
            }
            if(search(s,e,v))
                ans.push_back(false);
            else
                ans.push_back(true);
            
        }
        
        // 0 1 2      5,7
        // 2 4 8
        
        // 0 1 2
        // 0 1 2
        
        
        return ans;
    }
};