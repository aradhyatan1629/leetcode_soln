class Solution {
public:
    vector<int> ans;
    
    void solve(string s,int n){
        if(stoi(s) > n){
            return;
        }
        
        ans.push_back(stoi(s));
        for(int i=0;i<=9;i++){
            solve(s+to_string(i),n);
        }
        
    }
    
    vector<int> lexicalOrder(int n) {
        for(int i=1;i<=9;i++){
            solve(to_string(i),n);
        }
        return ans;
    }
};