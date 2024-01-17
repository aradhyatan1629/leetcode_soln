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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> ans(2);
        DisjointSet ds(n);
        
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0],v=edges[i][1];
            int pu = ds.findUPar(u),pv = ds.findUPar(v);
            if(pu == pv)
            {
                ans[0]=u,ans[1]=v;
            }
            ds.unionBySize(u,v);
        }
        return ans;
    }
};






















