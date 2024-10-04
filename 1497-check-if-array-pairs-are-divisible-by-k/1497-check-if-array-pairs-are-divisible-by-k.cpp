class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(int i=0;i<arr.size();i++){
            int rem = ((arr[i]%k)+k)%k; // to handle both -ve and +ve nos.
            m[rem]++;
        }
        if(m[0]%2!=0)
            return false;
        
        for(int i=1;i<=k/2;i++){
            if(m[i] != m[k-i])
                return false;
        }
        
        return true;
    }
};





/*
(a%k+b%k)%k = 0, if (a+b)%k = 0
problem converts to 2 sum problem
using remainders
*/






