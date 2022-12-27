class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n=rocks.size();
        vector<int> v;
        for(int i=0;i<capacity.size();i++)
        {
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(),v.end());
        for(auto &x:v)
        {
            if(x<=additionalRocks)
            {
                additionalRocks-=x;
                x=0;
            }
            else if(x>additionalRocks)
            {
                break;
            }
            else if(additionalRocks==0)
            {
                break;
            }
        }
        int cnt=0;
        for(auto x:v)
        {
            if(x==0)
            {
                cnt++;
            }
        }
        return cnt;
    }
};

// (0,1,1,1)