class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        int n = happiness.size();
        int d = 0;
        sort(happiness.begin(),happiness.end());
        for(int i=n-1;i>=0 && k>0;i--)
        {
            if(happiness[i]-d > 0)
                ans += happiness[i]-d;
            else
                break;
            d++;
            k--;
        }
        return ans;
    }
};