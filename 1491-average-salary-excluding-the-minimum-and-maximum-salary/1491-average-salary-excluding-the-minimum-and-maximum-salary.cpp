class Solution {
public:
    double average(vector<int>& sal) {
        double avg = 0;
        double sum=0;
        int mx = *max_element(sal.begin(),sal.end());
        int mn = *min_element(sal.begin(),sal.end());
        for(int i=0;i<sal.size();i++)
        {
            if(sal[i]==mx || sal[i]==mn)
            {
                continue;
            }
            else
            {
                sum+=sal[i];
            }
        }
        return sum/(sal.size()-2);
    }
};