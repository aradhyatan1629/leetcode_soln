class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> allPrefix;
        
        for(int i=0;i<arr1.size();i++){
            int x = arr1[i];
            while(x){
                if(allPrefix.find(x) == allPrefix.end()){
                    allPrefix.insert(x);
                    x/=10;
                }
                else{
                    break;
                }
            }
        }
        
        
        int mx = 0;
        for(int i=0;i<arr2.size();i++){
            int x = arr2[i];
            while(x){
                if(allPrefix.find(x) != allPrefix.end()){
                    int sz = to_string(x).size();
                    mx = max(mx,sz);
                    break;
                }
                x/=10;
            }
        }
        return mx;
    }
};