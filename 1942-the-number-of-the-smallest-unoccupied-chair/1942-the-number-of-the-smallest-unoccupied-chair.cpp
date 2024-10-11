class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // {leavingTime,seatNo}
        
        int target = times[targetFriend][0];
        sort(times.begin(),times.end());
        
        int ind = -1;
        for(int i=0;i<times.size();i++){
            if(times[i][0] == target){
                ind = i;
                break;
            }
        }
            
        priority_queue<int,vector<int>,greater<int>> emptySeats;
        int currSeat = 0;
        
        for(int i=0;i<ind;i++){
            int newArrive = times[i][0];
            while(!pq.empty() && pq.top().first <= newArrive){
                emptySeats.push(pq.top().second);
                pq.pop();
            }
            if(emptySeats.size() != 0){
                pq.push({times[i][1],emptySeats.top()});
                emptySeats.pop();
            }
            else{
                pq.push({times[i][1],currSeat});
                currSeat++;
            }
        }
        
        while(!pq.empty() && pq.top().first <= target){
            emptySeats.push(pq.top().second);
            pq.pop();
        }
        if(emptySeats.size() != 0)
            return emptySeats.top();
        
        return currSeat;
    }
};