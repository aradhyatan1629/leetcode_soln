class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        unordered_map<long long,long long> totalSum;
        unordered_map<int,int> totalCnt;
        for(int i=0;i<nums.size();i++)
        {
            totalSum[nums[i]]+=i;
            totalCnt[nums[i]]++;
        }
        vector<long long> ans;
        unordered_map<int,int> currCnt;
        unordered_map<long long,long long> currSum;
        for(int i=0;i<nums.size();i++)
        {
            currCnt[nums[i]]++;
            currSum[nums[i]]+=i;
            long long rightSum = totalSum[nums[i]] - currSum[nums[i]];
            long long leftSum = currSum[nums[i]]-i;
            int rightCnt = totalCnt[nums[i]] - currCnt[nums[i]];
            int leftCnt = currCnt[nums[i]]-1;
            long long r = rightSum - ((long long)(i)*(long long)(rightCnt));
            long long l = ((long long)(i)*(long long)(leftCnt)) - leftSum;
            ans.push_back(r+l);
        }
        return ans;
    }
};

// after trying few test cases easy formula derived is - 
/*
for each index the answer is - 
r = rightSum - (curr index * rightCount)
l = (curr index * leftCnt) - leftSum
ans = r+l
*/
