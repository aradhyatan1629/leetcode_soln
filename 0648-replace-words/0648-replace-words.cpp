/*
["a", "aa", "aaa", "aaaa"]
"a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa"
*/

class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        string ans;
        string temp;
        unordered_map<string,int> m;
        for(auto x:dictionary)
        {
            m[x]=1;
        }
        int flag=1;
        for(int i=0;i<sentence.size();i++)
        {
            if((sentence[i]>=97 and sentence[i]<=122) and flag==1)
            {
                temp+=sentence[i];
            }
            if(m[temp]==1 and flag==1)
            {
                ans+=temp;
                ans+=" "; 
                temp.clear();
                flag=-1;
            }
            else
            {
                if(sentence[i]==' ' and temp.size()==0)
                {
                    flag=1;
                }
                else if(sentence[i]==' ' and temp.size()!=0)
                {
                    ans+=temp;
                    ans+=" ";
                    temp.clear();
                    flag=1;
                }
            }
        }
        if(temp.size()!=0)
        {
            ans+=temp;
            ans+=" ";
        }
        ans.erase(ans.end()-1);
        return ans;
    }
};