/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    void dfs(int node,unordered_map<int,int> &vis,unordered_map<int,vector<int>> &m,unordered_map<int,int> &m1,int &ans)
    {
        vis[node]=1;
        ans+=m1[node];
        for(auto it:m[node])
        {
            if(!vis[it])
                dfs(it,vis,m,m1,ans);
        }
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        unordered_map<int,vector<int>> m;  //{id - {direct subordinates}}
        unordered_map<int,int> m1; //{id - importance}
        
        for(int i=0;i<employees.size();i++)
        {
            int id = employees[i]->id;int imp = employees[i]->importance;
            m1[id] = imp;
            for(auto x:employees[i]->subordinates)
            {
                m[id].push_back(x);
            }
        }
        unordered_map<int,int> vis;
        int ans = 0;
        dfs(id,vis,m,m1,ans);
        return ans;
    }
};