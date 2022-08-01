class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        sort(stones.begin(),stones.end());
        int n = stones.size();
        for(int i=n-1;i>0;i--)
        {
            stones[i - 1] = stones[i] - stones[i - 1];
            sort(stones.begin(),stones.end());
        }
        return stones[0];
    }
};