class Solution {
public:
    string largestGoodInteger(string num) {
        char mx='\0';
        string ans;
        int i=0,j=0,k=3;
        int n = num.size();
        string word;
        while(j<n)
        {
            word+=num[j];
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                int sum = word[0]-'0' + word[1]-'0' + word[2]-'0';
                int sum1 = (num[i]-'0')*3;
                if(sum==sum1 and num[i]>mx and word[0]==word[1] and word[0]==word[2])
                {
                    ans=word;
                    mx=num[i];
                }
                word.erase(word.begin());
                i++;
                j++;
            }
        }
        return ans;
    }
};