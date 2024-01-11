class Solution {
public:
    int minimumOperationsToMakeEqual(int x, int y) {
        if(x==y)
            return 0;
        queue<pair<int,int>> q;
        vector<int> dist(1e5,1e9);
        dist[x]=0;
        q.push({0,x});
        
        while(!q.empty())
        {
            int steps = q.front().first;
            int node = q.front().second;
            
            q.pop();
            if(node == y)
                return steps;
            
            if(node%11==0)
            {
                int adjNode = node/11;
                if(steps+1 < dist[adjNode]){dist[adjNode]=steps+1;q.push({steps+1,adjNode});}
            }
            if(node%5==0)
            {
                int adjNode = node/5;
                if(steps+1 < dist[adjNode]){dist[adjNode]=steps+1;q.push({steps+1,adjNode});}
            }
            if(steps+1 < dist[node+1])
            {
                dist[node+1]=steps+1;
                q.push({steps+1,node+1});
            }
            if(steps+1 < dist[node-1] and node-1!=0)
            {
                dist[node-1]=steps+1;
                q.push({steps+1,node-1});
            }
        }
        return -1;
    }
};