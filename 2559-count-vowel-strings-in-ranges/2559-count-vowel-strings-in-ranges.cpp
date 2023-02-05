class Solution {
public:
    bool isVowel(char ch1,char ch2)
    {
        bool flag1=false,flag2=false;
        if(ch1=='a' or ch1=='e' or ch1=='i' or ch1=='o' or ch1=='u')
        {
            flag1=true;
        }
        if(ch2=='a' or ch2=='e' or ch2=='i' or ch2=='o' or ch2=='u')
        {
            flag2=true;
        }
        return (flag1 and flag2);
    }
    
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> ans;
        vector<int> pre(n,0);
        char ch1=words[0][0];
        char ch2=words[0][words[0].size()-1];
        if(isVowel(ch1,ch2)==true)
        {
            pre[0]=1;
        }
        else
        {
            pre[0]=0;
        }
        for(int i=1;i<words.size();i++)
        {
            int sz=words[i].size();
            char ch1=words[i][0];
            char ch2=words[i][sz-1];
            if(isVowel(ch1,ch2)==true)
            {
                pre[i]=pre[i-1]+1;
            }
            else
            {
                pre[i]=pre[i-1];
            }
        }
        for(int i=0;i<queries.size();i++)
        {
            int l=queries[i][0];
            int r=queries[i][1];
            if(l==r)
            {
                char ch1=words[l][0];
                char ch2=words[l][words[l].size()-1];
                if(isVowel(ch1,ch2)==true)
                {
                    ans.push_back(1);
                }
                else
                {
                    ans.push_back(0);
                }
            }
            else if(l==0 and r>0)
            {
                ans.push_back(pre[r]);
            }
            else if(l>0 and r>0)
            {
                ans.push_back(pre[r]-pre[l-1]);
            }
        }
        return ans;
    }
};


// 1 1 2 3 4


