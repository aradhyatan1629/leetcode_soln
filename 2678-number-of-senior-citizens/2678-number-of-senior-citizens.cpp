class Solution {
public:
    int countSeniors(vector<string>& details) {
        int cnt = 0;
        for(int i=0;i<details.size();i++)
        {
            if(details[i][11]-'0'>=6)
            {
                if(details[i][12]-'0' > 0)
                    cnt++;
                else if(details[i][11]-'0'>6)
                    cnt++;
            }
       }
        return cnt;
    }
};