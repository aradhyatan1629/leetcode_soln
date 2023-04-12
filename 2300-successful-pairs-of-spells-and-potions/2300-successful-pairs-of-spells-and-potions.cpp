class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++)
        {
            int low = 0;
            int high = potions.size()-1;
            while(low<=high)
            {
                int mid = low+(high-low)/2;
                long long s = spells[i];
                long long p = potions[mid];
                if(s*p>=success)
                {
                    high=mid-1;
                }
                else
                {
                    low=mid+1;
                }
            }
            ans.push_back(potions.size()-1-high);
        }
        return ans;
    }
};



/*

1 2 3 4 5


*/