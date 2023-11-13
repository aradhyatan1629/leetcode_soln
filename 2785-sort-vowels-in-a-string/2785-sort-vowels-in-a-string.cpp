class Solution {
public:
    
    bool isVowel(char ch)
    {
        if(ch=='A' or ch=='a' or ch=='E' or ch=='e' or ch=='I' or ch=='i' or ch=='O' or ch=='o' or ch=='U' or ch=='u')
        {
            return true;
        }
        return false;
    }
    
    string sortVowels(string s) {
        priority_queue<int,vector<int>,greater<int>> pq;
        string t=s;
        
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                pq.push(s[i]);
            }
            else
            {
                t[i]=s[i];
            }
        }
        for(int i=0;i<s.size();i++)
        {
            if(isVowel(s[i]))
            {
                t[i]=char(pq.top());
                pq.pop();
            }
        }
        return t;
    }
};