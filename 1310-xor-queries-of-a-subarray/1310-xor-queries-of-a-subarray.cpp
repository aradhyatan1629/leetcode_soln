class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size();
        vector<int> prefXor(n,0);
        prefXor[0] = arr[0];
        
        for(int i=1;i<n;i++){
            prefXor[i] = (prefXor[i-1]^arr[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int start = queries[i][0],end = queries[i][1];
            if(start == 0)
                ans.push_back(prefXor[end]);
            else
                ans.push_back(prefXor[end]^prefXor[start-1]);
        }
        return ans;
    }
};

