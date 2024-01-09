class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        st.erase(beginWord);
        
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        
        while(!q.empty())
        {
            string word = q.front().first;
            int len = q.front().second;
            q.pop();
            if(word == endWord)
                return len;
            
            for(int i=0;i<word.size();i++)
            {
                string t = word;
                for(char ch='a';ch<='z';ch++)
                {
                    t[i] = ch;
                    if(st.find(t)!=st.end())
                    {
                        st.erase(t);
                        q.push({t,len+1});
                    }
                }
            }
        }
        return 0;
    }
};