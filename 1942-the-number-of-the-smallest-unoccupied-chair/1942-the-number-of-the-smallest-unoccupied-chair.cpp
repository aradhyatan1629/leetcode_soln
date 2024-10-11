class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // {leaving,seatNo}
        
        int targetA = times[targetFriend][0];
        sort(times.begin(),times.end());
        int currSeat = 0;
        
        priority_queue<int,vector<int>,greater<int>> emptySeats;
        
        for(int i=0;i<times.size();i++){
            if(times[i][0] < targetA){
                while(!pq.empty() && pq.top().first <= times[i][0]){ // some people have left
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
            else if(times[i][0] == targetA){
                // cout<<"hi "<<pq.size()<<endl;
                while(!pq.empty() && pq.top().first <= times[i][0]){ // some people have left
                    emptySeats.push(pq.top().second);
                    pq.pop();
                }
                // cout<<"hi "<<pq.size()<<endl;
                if(emptySeats.size() != 0){
                   return emptySeats.top();
                }
                return currSeat;
            }
        }
        return -1;
    }
};