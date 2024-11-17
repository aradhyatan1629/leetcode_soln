class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        long long  sum=0;
        int mint = INT_MAX;
        map<long long ,int>mp;
        mp[0] = -1;
        for(int j=0;j<nums.size();j++){

            sum+=nums[j];
            mp[sum] = j;


        auto it = mp.begin();
        while(it!=mp.end() && sum-it->first>=k){
            mint = min(mint, j-it->second);
            mp.erase(it);
            it++;
            }

        }

        return mint==INT_MAX?-1:mint;
    }
};