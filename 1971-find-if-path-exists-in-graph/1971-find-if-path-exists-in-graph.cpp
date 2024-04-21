class DisjointSet
{
    private:
        vector<int> rank,parent,size;
    public:
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0;i<=n;i++)
            {
                parent[i] = i;
                size[i] = 1;
            }
        }
        
        int findPar(int node)
        {
            if(parent[node] == node)
                return node;
            return parent[node] = findPar(parent[node]);
        }
    
        void unionByRank(int u,int v)
        {
            int pu = findPar(u);
            int pv = findPar(v);
            if(pu == pv)
                return;
            if(rank[pu] < rank[pv])
            {
                parent[pu] = pv;
            }
            else if(rank[pv] < rank[pu])
            {
                parent[pv] = pu;
            }
            else
            {
                parent[pv] = pu;
                rank[pu]++;
            }
        }
    
        void unionBySize(int u,int v)
        {
            int pu = findPar(u);
            int pv = findPar(v);
            if(pu == pv)
                return;
            if(size[pu] < size[pv])
            {
                parent[pu] = pv;
                size[pv]+=size[pu];
            }
            else if(size[pv] < size[pu])
            {
                parent[pv] = pu;
                size[pu] += pv;
            }
            else
            {
                parent[pv] = pu;
                size[pu] += pv;
            }
        }
};

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);
        for(int i=0;i<edges.size();i++)
        {
            if(ds.findPar(edges[i][0]) != ds.findPar(edges[i][1]))
                ds.unionByRank(edges[i][0],edges[i][1]);
        }
        if(ds.findPar(source) == ds.findPar(destination))
            return true;
        return false;
    }
};