class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        stack<int> st;
        int sum = 0;
        reverse(sandwiches.begin(),sandwiches.end());
        for(int i=0;i<students.size();i++)\
        {
            q.push(students[i]);
            sum+=students[i];
            st.push(sandwiches[i]);
        }
        // cout<<"sum "<<sum<<endl;
        while(!q.empty())
        {
            // cout<<"st "<<st.top()<<" q "<<q.front()<<" sum "<<sum<<endl;
            if(st.top()==1 and sum==0)
                return q.size();
            else if(st.top()==0 and sum==q.size())
                return q.size();
            else if(st.top() == q.front())
            {
                if(q.front()==1)
                    sum--;
                st.pop(),q.pop();
            }
            else if(st.top() != q.front())
                q.push(q.front()),q.pop();
        }
        return 0;
    }
};