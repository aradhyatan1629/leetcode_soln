class Solution {
public:
    void solve(int ind,string &s,unordered_set<string> &st,int &mx){
        if(ind >= s.size()){
            int sz = st.size();
            mx = max(mx,sz);
            return;
        }
        for(int i=ind;i<s.size();i++){
            string sub = s.substr(ind,i-ind+1); //check if substring is present in set or not
            if(st.find(sub) == st.end()){
                st.insert(sub);
                solve(i+1,s,st,mx);
                st.erase(sub);
            }
        }
    }
    
    int maxUniqueSplit(string s) {
        int mx = 0;
        unordered_set<string> st;
        solve(0,s,st,mx);
        return mx;
    }
};