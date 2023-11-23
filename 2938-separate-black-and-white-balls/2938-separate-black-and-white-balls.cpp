class Solution {
public:
    long long minimumSteps(string s) {
        long long ans=0;
        int low=0,high=s.size()-1;
        while(low<=high)
        {
            if(s[low] == '1' and s[high] == '0')
            {
                swap(s[low],s[high]);
                ans+=(high-low);
                low++,high--;
            }
            else if(s[low] == '0')
            {
                low++;
            }
            else
            {
                high--;
            }
        }
        return ans;
    }
};



