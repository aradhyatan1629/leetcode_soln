class Solution {
public:
    string clearStars(string s) {
        
        map<char,priority_queue<int>> m;
        set<int> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '*' && m.size()>0){
                auto it = m.begin();
                int ind = it->second.top();
                st.insert(ind);
                it->second.pop();
                if(it->second.empty()){
                    m.erase(it->first);
                }
            }
            else if(s[i] != '*'){
                m[s[i]].push(i);
            }
        }
        
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*' && st.find(i) == st.end())
                ans += s[i];
        }
        
        
        
        return ans;
    }
};



/*

eada*cf


*/