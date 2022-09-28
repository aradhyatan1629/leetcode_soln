class Solution {
public:
    bool winnerOfGame(string colors) {
        int movesalice=0;
        int movesbob=0;
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]=='A' and colors[i-1]=='A')
            {
                int j=i+1;
                int cnt=2;
                if(j>=colors.size())
                {
                    continue;
                }
                while(colors[j]=='A')
                {
                    cnt++;
                    // cout<<"cnt in while:"<<cnt<<endl;
                    j++;
                }
                i=j;
                // cout<<"cnt:"<<cnt<<endl;
                if(cnt>=3)
                {
                    movesalice+=cnt-2;
                }
            }
        }
        for(int i=1;i<colors.size();i++)
        {
            if(colors[i]=='B' and colors[i-1]=='B')
            {
                int j=i+1;
                int cnt=2;
                if(j>=colors.size())
                {
                    continue;
                }
                while(colors[j]=='B')
                {
                    cnt++;
                    // cout<<"cnt in while:"<<cnt<<endl;
                    j++;
                }
                i=j;
                // cout<<"cnt:"<<cnt<<endl;
                if(cnt>=3)
                {
                    movesbob+=cnt-2;
                }
            }
        }
        // cout<<movesalice<<endl;
        // cout<<movesbob;
        if(movesalice>movesbob)
        {
            return true;
        }
        return false;
    }
};