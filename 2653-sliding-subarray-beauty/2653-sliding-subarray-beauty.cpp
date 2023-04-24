class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        map<int,int> m;
        vector<int> ans;
        int i=0,j=0,n=nums.size();
        int neg=0;
        
        while(j<n)
        {
            m[nums[j]]++;
            if(nums[j]<0)
            {
                neg++;
            }
            
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(neg>=x)
                {
                    int t = 0;
                    for(auto it:m)
                    {
                        t += it.second;
                        if(t>=x)
                        {
                            ans.push_back(it.first);
                            break;
                        }
                    }
                }
                else
                {
                    ans.push_back(0);
                }
                
                m[nums[i]]--;
                if(m[nums[i]]==0)
                {
                    m.erase(nums[i]);
                }
                if(nums[i]<0)
                {
                    neg--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};



/*

[9,13,-26,47,29]
9
4

-49 - 1
-39 - 1
-26 - 1
-14 - 2
 9  - 1
 13 - 1
 29 - 1
 47 - 1



 
*/




