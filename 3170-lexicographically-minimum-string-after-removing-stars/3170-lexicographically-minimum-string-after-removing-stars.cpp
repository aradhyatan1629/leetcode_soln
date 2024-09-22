class Solution {
public:
    string clearStars(string s) {
        
        map<char,vector<int>> m;
        set<int> st;
        
        for(int i=0;i<s.size();i++){
            if(s[i] == '*' && m.size()>0){
                auto it = m.begin();
                int ind = it->second.back();
                st.insert(ind);
                it->second.pop_back();
                if(it->second.size() == 0)
                    m.erase(it->first);
            }
            else if(s[i] != '*'){
                m[s[i]].push_back(i);
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