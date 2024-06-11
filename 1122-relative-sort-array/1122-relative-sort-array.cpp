class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> v(1001,0);
        vector<int> ans;
        for(int i=0;i<arr1.size();i++)
            v[arr1[i]]++;
        
        for(int i=0;i<arr2.size();i++)
        {
            while(v[arr2[i]])
            {
                ans.push_back(arr2[i]);
                v[arr2[i]]--;
            }
        }
        for(int i=0;i<v.size();i++)
        {
            while(v[i]>0)
            {
                ans.push_back(i);
                v[i]--;
            }
        }
        return ans;
    }
};