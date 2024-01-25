class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++)
            s.insert(nums[i]);
        int mxLen=0;
        for(auto x:s)
        {
            if(s.find(x-1)==s.end())
            {
                int cnt=1;
                int t = x+1;
                while(s.find(t)!=s.end())
                {
                    cnt++;
                    t++;
                }
                mxLen=max(mxLen,cnt);
            }
        }
        return mxLen;
    }
};

//tc - O(n) + O(2n) , under the assumption our unordered_set is taking O(1) for all operations.

/*
basically the intution is as follows - 
if you are at a number say 3 then normally you would go ahead
to check the consecutive sequence like from 3 to 4 to 5 to 6 etc
but in optimized approach say we have a consecutive sequence like 1,2,3,4
and u are at 3 now instead of going forward we will check whether we have
3-1 i.e 2 in the set? if yes then 3 is not the STARTING POINT of the sequence
similarly for 2 , 2-1=1 which is there in the set 
but for 1, 1-1=0 which is not there in the set.
hence we will start the linear search from 1 to count the length of consecutive sequence
1,1+1=2,2+1=3,3+1=4. hence largest consecutive sequence length = 4
*/