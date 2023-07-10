class Solution {
public:
    bool dfs(int node,int col,int color[],vector<vector<int>> &graph)
    {
        color[node] = col;
        for(auto adjacentNode:graph[node])
        {
            if(color[adjacentNode]==-1)
            {
                if(dfs(adjacentNode,!col,color,graph)==false)
                {
                    return false;
                }
            }
            else if(color[adjacentNode]==col)
            {
                return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int V = graph.size();
        int color[V];
        for(int i=0;i<V;i++)
        {
            color[i] = -1;
        }
        for(int i=0;i<V;i++)      //checking for all the connected components
        { 
            if(color[i]==-1)
            {
                if(dfs(i,0,color,graph)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
};