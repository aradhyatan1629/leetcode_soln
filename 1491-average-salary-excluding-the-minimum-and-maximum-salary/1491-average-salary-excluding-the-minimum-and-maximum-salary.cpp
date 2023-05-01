class Solution {
public:
    double average(vector<int>& salary) {
        int mx = *max_element(salary.begin(),salary.end());
        int mn = *min_element(salary.begin(),salary.end());
        int sum = accumulate(salary.begin(),salary.end(),0);
        
        double avg = ((sum - (mx+mn))/double(salary.size()-2));
        return avg;
    }
};