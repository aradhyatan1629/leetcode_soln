class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int flag=1;
        int cnt=0;
        for(int i=0;i<arr1.size();i++)
        {
            flag=1;
            for(int j=0;j<arr2.size();j++)
            {
                if(abs(arr1[i]-arr2[j])<=d)
                {
                    flag=-1;
                }
            }
            if(flag==1)
            {
                cnt++;
            }
        }
        return cnt;
    }
};