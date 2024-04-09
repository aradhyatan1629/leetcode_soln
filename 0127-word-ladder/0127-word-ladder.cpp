class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<int,string>> q;
        unordered_set<string> s(wordList.begin(),wordList.end());
        s.erase(beginWord);
        q.push({1,beginWord});
        
        while(!q.empty())
        {
            int steps = q.front().first;
            string word = q.front().second;
            q.pop();
            if(word==endWord)
                return steps;
            for(int i=0;i<word.size();i++)
            {
                string t = word;
                for(char j='a';j<='z';j++)
                {
                    t[i] = j;
                    if(s.find(t)!=s.end())
                    {
                        s.erase(t);
                        q.push({steps+1,t});
                    }
                }
            }
        }
        return 0;
    }
};