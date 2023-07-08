class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0,n=answerKey.size();
        int cnt=0,ans=0;
        
        while(j<n)                    //converting all false to true
        { 
            if(answerKey[j]=='F')
            {
                cnt++;
            }
            while(cnt>k)
            {
                if(answerKey[i]=='F')
                {
                    cnt--;
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        
        i=0,j=0,cnt=0;
        while(j<n)                  //converting all true to false
        {
            if(answerKey[j] == 'T')
            {
                cnt++;
            }
            while(cnt>k)
            {
                if(answerKey[i]=='T')
                {
                    cnt--;
                }
                i++;
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};





