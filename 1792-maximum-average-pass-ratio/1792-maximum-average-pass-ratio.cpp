class Solution 
{
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents)
    {
        int n = classes.size();
        priority_queue<pair<double,int>> pq;
        
        for(int i=0 ; i<n; i++)
        {
            double d = (classes[i][0]+1)*1.0/(classes[i][1]+1) - (classes[i][0])*1.0/(classes[i][1]);
            pq.push({d,i});
        }
        double ans = 0;
        while(extraStudents>0)
        {
            auto p = pq.top();
            pq.pop();
            int id = p.second;
            classes[id][0]++;
            classes[id][1]++;
            
            double d = (classes[id][0]+1)*1.0/(classes[id][1]+1) - (classes[id][0])*1.0/(classes[id][1]);
            pq.push({d,id});
            extraStudents--;
        }
        for(int i=0 ; i<n ; i++)
            ans += classes[i][0]*1.0/classes[i][1];
        
        ans /= n;
        return ans;
    }
};