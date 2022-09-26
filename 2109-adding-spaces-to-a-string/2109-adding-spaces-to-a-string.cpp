class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans;
        int cnt=0;
        int j=0;
        for(int i=0;i<s.size();i++)
        {
            if(j<spaces.size() and i==spaces[j])
            {
                ans+=" ";
                ans+=s[i];
                // cout<<"if i"<<i<<endl;
                j++;
                /*if(j>spaces.size())
                {
                    break;
                }*/
            }
            else
            {
                ans+=s[i];
                // cout<<"else i "<<i<<" "<<ans<<endl;
            }
        }
        // cout<<"ans"<<ans;
        return ans;
    }
};