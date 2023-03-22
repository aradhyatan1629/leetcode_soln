class Solution {
public:
    bool checkValidGrid(vector<vector<int>>& grid) {
        unordered_set<int> st;
        map<int,pair<int,int>> m;
        if(grid[0][0]!=0)
        {
            return false;
        }
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                m[grid[i][j]] = {i,j};
                st.insert(grid[i][j]);
            }
        }
       /* for(auto x:m)
        {
            cout<<x.first<<" "<<x.second.first<<x.second.second<<endl;
        }*/
        auto it1=m.begin();
        for(auto it=m.begin();it!=m.end();it++)
        {
            if(it!=m.begin())
            {
                int r1 = it1->second.first;
                int c1 = it1->second.second;
                int r2 = it->second.first;
                int c2 = it->second.second;
                it1++;
                
                if((r1==r2+2 or r1==r2-2) and (c1==c2+1 or c1==c2-1))
                {
                    continue;
                }
                else if((c1==c2+2 or c1==c2-2) and (r1==r2+1 or r1==r2-1))
                {
                    continue;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;;
    }
};

// row +2 col+1,col-1
// row -2 col+1,col-1

// col +2 row+1,row-1
// col -2 row+1,row-1