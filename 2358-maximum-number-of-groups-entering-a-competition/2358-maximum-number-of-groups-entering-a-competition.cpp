class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        sort(grades.begin(),grades.end());
        
        int prevSum=0,currSum=0;
        int prevCount=0,currCount=0;
        int ans=0;
        
        for(int i=0;i<grades.size();i++)
        {
            currSum+=grades[i];
            currCount++;
            if(currCount>prevCount and currSum>prevSum)
            {
                ans++;
                prevSum = currSum;
                prevCount = currCount;
                currSum=currCount=0;
            }
        }
        return ans;
    }
};

