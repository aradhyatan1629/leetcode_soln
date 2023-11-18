class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currTime = 0;
        double avg=0.0;
        
        for(int i=0;i<customers.size();i++)
        {
            int arrival = customers[i][0];
            int time = customers[i][1];
            
            if(arrival < currTime)
            {
                avg += double(currTime+time-arrival);
                currTime = currTime + time;
            }
            else
            {
                avg += double(arrival+time - arrival);
                currTime = arrival + time;
            }
        }
        
        return avg/double(customers.size());
    }
};