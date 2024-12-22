class Solution {
public:
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        int q=queries.size();
        vector<int> ans(q,-1);
        unordered_map<int, vector<pair<int,int>>> map; //index ={max height, query number}
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> min_heap;

        int i=-1;
        for(auto j: queries){
            i++;
            int x = j[0];
            int y = j[1];
            int h_x =heights[x];
            int h_y =heights[y];

            if(y>x && h_y>h_x){
                ans[i]=y;
            }
            else if(x>y && h_x>h_y){
                ans[i]=x;
            }
            else if(x==y){
                ans[i]=x;
            }
            else{
                map[max(x,y)].push_back({max(h_x,h_y), i});
            }
        }
        for(int i=0; i<n; i++){

            while(!min_heap.empty() && min_heap.top().first < heights[i]){
                ans[min_heap.top().second]=i;
                min_heap.pop();
            }
            for(auto j:map[i]){
                min_heap.push(j);
            }
        }
        return ans;
    }
};