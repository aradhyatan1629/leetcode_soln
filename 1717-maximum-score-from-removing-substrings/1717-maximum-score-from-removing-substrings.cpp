class Solution {
public:
    void solve(string &s,string t,int &score,int add,stack<char> &st)
    {
        for(int i=0;i<s.size();i++)
        {
            if(st.empty())
            {
                st.push(s[i]);
            }
            else if(!st.empty() and (st.top()==t[0] and s[i]==t[1]))
            {
                score+=add;
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    
    int maximumGain(string s, int x, int y) {
        int score=0;
        stack<char> st;
        if(x>=y)
        {
            solve(s,"ab",score,x,st);
            s.clear();
            while(!st.empty()){s+=st.top();st.pop();}
            reverse(s.begin(),s.end());
            solve(s,"ba",score,y,st);
        }
        else 
        {
            solve(s,"ba",score,y,st);
            s.clear();
            while(!st.empty()){s+=st.top();st.pop();}
            reverse(s.begin(),s.end());
            solve(s,"ab",score,x,st);
        }
        return score;
    }
};



/*
first take the substring that will give the max score 
then take the remaining one
*/

