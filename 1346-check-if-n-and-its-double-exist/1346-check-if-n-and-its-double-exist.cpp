class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto x:arr)
            m[x]++;
        
        
        
        for(auto x:m){
           if(m.find(x.first*2) != m.end()){
               if(x.first != x.first*2)
                   return true;
               else if(m[x.first]>1)
                   return true;
           }
        }
        return false;
    }
};