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
                parent[i]=i;
                size[i]=1;
            }
        }
        int findUPar(int node)
        {
            if(node == parent[node])
            {
                return node;
            }
            return parent[node] = findUPar(parent[node]);
        }
        void unionByRank(int u,int v)
        {
            int pu = findUPar(u);
            int pv = findUPar(v);
            if(pu == pv)return;
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
            int pu = findUPar(u);
            int pv = findUPar(v);
            if(pu == pv)return;
            if(size[pu] < size[pv]) 
            {
                parent[pu] = pv;
                size[pv]+=size[pu];
            }
            else if(size[pv] < size[pu])
            {
                parent[pv] = pu;
                size[pu]+=size[pv];
            }
            else
            {
                parent[pv] = pu;
                size[pu]++;
            }
        }
};


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int components=0,extraEdges=0;
        for(int i=0;i<connections.size();i++)
        {
            int u = connections[i][0],v = connections[i][1];
            if(ds.findUPar(u) == ds.findUPar(v))
                extraEdges++;
            else
                ds.unionBySize(u,v);
        }
        for(int i=0;i<n;i++)
        {
            if(ds.findUPar(i) == i)
                components++;
        }
        if(extraEdges >= components-1)
            return components-1;
        return -1;
    }
};






/*

Using disjoint set data structure this problem can also be solved
we first create the dsu
then find the total number of components => total number of nodes which are ultimate parents of themselves in the ultimate parent array is the total number of components.
Count the extra edges => if 2 nodes have the same ultimate parent then that is an extra edge.
if(extra edges >= comonents-1)return components-1
else return -1;

Time: O(n + m*α(n)) ≈ O(n + m), m is the length of connections (union operations).

*/




