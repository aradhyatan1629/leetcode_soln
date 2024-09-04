class Solution {
public:
    void solve(int &curr_x,int &curr_y,int &mx,int dir,unordered_map<int,unordered_set<int>> &m,int k)
    {
        while(k--)
        {
            if(dir == 0)  // +y
            {
                if(m[curr_x].find(curr_y+1) != m[curr_x].end())
                    return;
                curr_y++;
                int d = (curr_x*curr_x) + (curr_y*curr_y);
                mx = max(mx,d);
            }
            else if(dir == 1 or dir == -3) // +x
            {
                if(m[curr_x+1].find(curr_y) != m[curr_x+1].end())
                    return;
                curr_x++;
                int d = (curr_x*curr_x) + (curr_y*curr_y);
                mx = max(mx,d);
            }
            else if(dir == 2 or dir == -2) // -y
            {
                if(m[curr_x].find(curr_y-1) != m[curr_x].end())
                    return;
                curr_y--;
                int d = (curr_x*curr_x) + (curr_y*curr_y);
                mx = max(mx,d);
            }
            else if(dir == 3 || dir == -1)  // -x
            {
                if(m[curr_x-1].find(curr_y) != m[curr_x-1].end())
                    return;
                curr_x--;
                int d = (curr_x*curr_x) + (curr_y*curr_y);
                mx = max(mx,d);
            }
        }
        // cout<<dir<<" "<<curr_x<<" "<<curr_y<<" "<<mx<<endl;
       
    }
    
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_map<int,unordered_set<int>> m;
        
        for(int i=0;i<obstacles.size();i++)
        {
            int x = obstacles[i][0],y = obstacles[i][1];
            m[x].insert(y);
        }
        
        int mx = 0,right=0;
        
        int curr_x=0;
        int curr_y=0;
        
        for(int i=0;i<commands.size();i++)
        {
            if(commands[i] == -1 || commands[i] == -2)
            {
                commands[i]==-1 ? right++ : right--;
            }
            else
            {
                int dir = abs(right)%4;
                // cout<<"right "<<right<<endl;
                if(right<0)dir*=-1;
                solve(curr_x,curr_y,mx,dir,m,commands[i]);
            }
        }
        
        
        return mx;
    }
};