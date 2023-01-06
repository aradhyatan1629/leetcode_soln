class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        int cnt=0;
        unordered_set<string> s;
        for(int i=0;i<emails.size();i++)
        {
            string temp;
            int flag=-1;
            for(int j=0;j<emails[i].size();j++)
            {
                if(emails[i][j]=='.' and flag==-1)
                {
                    continue;
                }
                else if(emails[i][j]=='@' and flag==-1)
                {
                    temp+=emails[i][j];
                    flag=1;
                }
                else if(emails[i][j]=='.' and flag==1 or emails[i][j]=='+' and flag==1)
                {
                    temp+=emails[i][j];
                }
                else if(emails[i][j]>=97 and emails[i][j]<=122)
                {
                    temp+=emails[i][j];
                }
                else if(emails[i][j]=='+' and flag==-1)
                {
                    while(emails[i][j]!='@')
                    {
                        j++;
                    }
                    temp+=emails[i][j];
                    flag=1;
                }

            }
            s.insert(temp);
        }
        return s.size();
    }
};