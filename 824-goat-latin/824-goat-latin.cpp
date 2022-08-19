class Solution {
public:
    bool isvowel(char x)
    {
        if(x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='A' or x=='E' or x=='I' or x=='O' or x=='U')
        {
            return true;
        }
        return false;
    }
    string toGoatLatin(string sentence) {
        string word;
        string ans;
        int n = sentence.size();
        int cnt=1;
        int temp=cnt;
        for(int i=0;i<n;++i)
        {
            temp=cnt;
            if(sentence[i]==' ')
            {
                if(isvowel(word[0]))
                {
                    word+="ma";
                    while(cnt--)
                    {
                        word+='a';
                    }
                    ans+=word;
                    ans+=' '; 
                }
                else
                {
                    word.push_back(word[0]);
                    word.erase(word.begin());
                    word+="ma";
                    while(cnt--)
                    {
                        word+='a';
                    }
                    ans+=word;
                    ans+=' ';
                }
                cnt=temp+1;
                word.clear();
            }
            else
            {
                word+=sentence[i];
            }
        }
        if(isvowel(word[0]))
           {
            word+="ma";
            while(cnt--)
            {
                word+='a';
            }
            ans+=word;
        }
        else
        {
            word.push_back(word[0]);
            word.erase(word.begin());
            word+="ma";
            while(cnt--)
            {
                word+='a';
            }
            ans+=word;
        }
        return ans;
    }
};