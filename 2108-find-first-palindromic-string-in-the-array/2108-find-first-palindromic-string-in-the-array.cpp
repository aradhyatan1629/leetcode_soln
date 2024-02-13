class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            int j=0,k=words[i].size()-1;
            bool flag=true;
            while(j<k)
            {
                if(words[i][j]!=words[i][k])
                {
                    flag=false;break;
                }
                j++;k--;
            }
            if(flag)return words[i];
        }
        return "";
    }
};