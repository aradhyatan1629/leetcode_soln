class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> s;
        int n = sandwiches.size();
        for(auto x:students)
        {
            q.push(x);
        }
        for(int i=0;i<sandwiches.size();i++)
        {
            s.push(sandwiches[n-i-1]);
        }
        int able=0;
        while(!s.empty())
        {
            if(s.top()==q.front())
            {
                q.pop();
                s.pop();
                able++;
            }
            else
            {
               int cnt=0;
                while(cnt<q.size() and q.front()!=s.top())
                {
                    int x = q.front();
                    q.pop();
                    q.push(x);
                    cnt++;
                }
                if(cnt==q.size())
                {
                    return n-able;
                }
            }
        }
        return 0;
    }
};










