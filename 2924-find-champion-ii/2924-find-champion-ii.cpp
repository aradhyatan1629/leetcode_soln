class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unordered_set<int> s;
        for(int i=0;i<edges.size();i++){
            s.insert(edges[i][1]);
        }
        
        int cnt = 0;
        int ans = -1;
        for(int i=0;i<n;i++){
            if(s.find(i) == s.end()){
                ans = i;
                cnt++;
            }
        }
        if(cnt > 1)
            return -1;
        return ans;
    }
};