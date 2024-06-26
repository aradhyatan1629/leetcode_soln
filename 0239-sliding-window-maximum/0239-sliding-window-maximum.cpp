class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> m;
        priority_queue<int> pq;
        int i=0,j=0,n=nums.size();
        
        while(j<n)
        {
            m[nums[j]]++;
            pq.push(nums[j]);
            if(j-i+1<k)
            {
                j++;
            }
            else if(j-i+1==k)
            {
                if(m[pq.top()]!=0)
                {
                    ans.push_back(pq.top());
                }
                else
                {
                    while(pq.size()>0 and m[pq.top()]==0)
                    {
                        pq.pop();
                    }
                    ans.push_back(pq.top());
                }
                if(m[nums[i]]>=1)
                {
                    m[nums[i]]--;
                }
                i++;
                j++;
            }
        }
        return ans;
    }
};