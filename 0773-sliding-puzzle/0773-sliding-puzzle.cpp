class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int r = board.size();
        int c = board[0].size();
        
        string source;
        string target = "123450";
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                source += to_string(board[i][j]);
            }
        }
        
        unordered_map<int,vector<int>> m;  // 0 kis kis se swap mar sakta hai
        m[0] = {1,3}; m[1] = {0,2,4}; m[2] = {1,5};
        m[3] = {0,4}; m[4] = {1,3,5}; m[5] = {2,4};
        
        
        unordered_map<string,int> vis;
        queue<pair<string,int>> q;
        
        vis[source] = 1;
        q.push({source,0});
        
        int ans = INT_MAX;
        while(!q.empty()){
            string s = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(s == target){
                ans = min(ans,lvl);
            }
            int ind = -1;
            for(int i=0;i<s.size();i++){
                if(s[i] == '0'){
                    ind = i;
                    break;
                }
            }
            for(auto x:m[ind]){
                string temp = s;
                swap(temp[ind],temp[x]);
                if(vis.find(temp) == vis.end()){
                    vis[temp] = 1;
                    q.push({temp,lvl+1});
                }
            }
        }
        if(ans == INT_MAX)
            return -1;
        return ans;
    }
};