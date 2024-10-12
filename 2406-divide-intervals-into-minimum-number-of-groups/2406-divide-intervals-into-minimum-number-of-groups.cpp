class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        priority_queue<int,vector<int>,greater<int>> pq;
        
        for(vector<int> &it:intervals){
            int start = it[0];
            int end = it[1];
            
            if(!pq.empty() && pq.top() < start){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};