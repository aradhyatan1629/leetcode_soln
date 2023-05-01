class Solution {
public:
    double average(vector<int>& salary) {
        int mx = *max_element(salary.begin(),salary.end());
        int mn = *min_element(salary.begin(),salary.end());
        double avg = 0;
        int n = salary.size()-2;
        for(auto x:salary)
        {
            if(x==mx or x==mn)
            {
                continue;
            }
            else
            {
                avg+=x;
            }
        }
        return avg/n;
    }
};