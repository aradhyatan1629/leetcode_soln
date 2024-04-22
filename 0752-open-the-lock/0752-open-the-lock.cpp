class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> dead(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<pair<int,string>> q;
        visited.insert("0000");
        q.push({0,"0000"});
        
        while (!q.empty()) {
            int cnt = q.front().first;
            string s = q.front().second;
            q.pop();
            if (s == target)
                return cnt;
            
            if (dead.find(s) != dead.end())
                continue;
            
            for (int i = 0; i < s.size(); i++) {
                string s1 = s, s2 = s;
                s1[i] = (s[i] == '9' ? '0' : s[i] + 1);
                s2[i] = (s[i] == '0' ? '9' : s[i] - 1);
                
                if (visited.find(s1) == visited.end()) {
                    q.push({cnt + 1, s1});
                    visited.insert(s1);
                }
                if (visited.find(s2) == visited.end()) {
                    q.push({cnt + 1, s2});
                    visited.insert(s2);
                }
            }
        }
        return -1;
    }
      
};