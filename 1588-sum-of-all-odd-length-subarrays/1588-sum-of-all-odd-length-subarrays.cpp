class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int length=1;
        int sum=0,totsum=0;
        for(int i=0;i<arr.size();i++)
        {
            sum=0,length=1;
            for(int j=i;j<arr.size();j++)
            {
                sum+=arr[j];
                if(length%2==1)
                {
                    totsum+=sum;
                }
                length++;
            }
        }
        return totsum;
    }
};