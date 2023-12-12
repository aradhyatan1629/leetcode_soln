class Solution {
public:
    static bool compare(int a,int b)
    {
        return abs(a) < abs(b);
    }
    
    bool canReorderDoubled(vector<int>& arr) {
        sort(arr.begin(),arr.end(),compare);
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        
        for(int i=0;i<arr.size();i++)
        {
            if(m[arr[i]]==0)
                continue;
            else if(m[arr[i]*2]==0)
                return false;
            m[arr[i]*2]--;
            m[arr[i]]--;
        }
        return true;
    }
};