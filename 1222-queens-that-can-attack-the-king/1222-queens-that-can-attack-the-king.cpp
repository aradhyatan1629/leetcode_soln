class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<char>> v(8,vector<char>(8,'a'));
        int x=king[0];
        int y=king[1];
        vector<vector<int>> ans;
        vector<int> temp;
        for(int i=0;i<queens.size();i++)
        {
            int x=queens[i][0];
            int y=queens[i][1];
            v[x][y]='q';
        }
        v[king[0]][king[1]]='k';
        for(int j=y+1;j<8;++j)
        {
            if(v[x][j]=='q')
            {
                temp.push_back(x);
                temp.push_back(j);
                ans.push_back(temp);
                break;
            }
        }
        temp.clear();
        for(int j=y-1;j>=0;j--)
        {
            if(v[x][j]=='q')
            {
                temp.push_back(x);
                temp.push_back(j);
                ans.push_back(temp);
                break;
            }
        }
        temp.clear();
        for(int i=x+1;i<8;++i)
        {
            if(v[i][y]=='q')
            {
                temp.push_back(i);
                temp.push_back(y);
                ans.push_back(temp);
                break;
            }
        }
        temp.clear();
        for(int i=x-1;i>=0;i--)
        {
            if(v[i][y]=='q')
            {
                temp.push_back(i);
                temp.push_back(y);
                ans.push_back(temp);
                break;
            }
        }
        temp.clear();
        for(int i=x-1,j=y-1;i>=0&&j>=0;i--,j--)
        {
            if(v[i][j]=='q')
            {
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
                break;
            }
        }
        temp.clear();
        for(int i=x+1,j=y+1;i<8&&j<8;i++,j++)
        {
            if(v[i][j]=='q')
            {
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
                break;
            }
        }
        temp.clear();
        for(int i=x-1,j=y+1;i>=0&&j<8;i--,j++)
        {
            if(v[i][j]=='q')
            {
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
                break;
            }
        }
        temp.clear();
        for(int i=x+1,j=y-1;i<8&&j>=0;i++,j--)
        {
             if(v[i][j]=='q')
            {
                temp.push_back(i);
                temp.push_back(j);
                ans.push_back(temp);
                break;
            }
        }
        return ans;
    }
};