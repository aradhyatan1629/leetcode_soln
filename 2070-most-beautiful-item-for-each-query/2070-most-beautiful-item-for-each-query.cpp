class Solution {
public:
    int search(vector<vector<int>> &items,int target){
        int low = 0;
        int high = items.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(items[mid][0] <= target){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return high;
    }
    
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(),items.end());
        int m = items.size();
        vector<int> pre(m,0);
        pre[0] = items[0][1];
        
        for(int i=1;i<pre.size();i++){
            pre[i] = max(pre[i-1],items[i][1]);
        }
        
        // for(auto x:pre)cout<<x<<" ";
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int ind = search(items,queries[i]);
            if(ind == -1)
                ans.push_back(0);
            else
                ans.push_back(pre[ind]);
        }
        
        
        return ans;
    }
};



/*
[1,2] [2,4] [3,2] [3,5] [5,6]

2 4 4 5 6


*/