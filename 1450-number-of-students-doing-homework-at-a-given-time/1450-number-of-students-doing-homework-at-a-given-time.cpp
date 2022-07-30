class Solution {
public:
    int busyStudent(vector<int>& st, vector<int>& en, int qu) {
        int cnt=0;
        for(int i=0;i<st.size();i++)
        {
            int start = st[i];
            int end = en[i];
            if(qu>=start and qu<=end)
            {
                cnt++;
            }
        }
        return cnt;
    }
};