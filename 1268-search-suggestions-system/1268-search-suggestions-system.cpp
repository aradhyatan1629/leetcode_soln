class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string search) {
        vector<string> temp(products);
        vector<vector<string>> ans;
        sort(temp.begin(),temp.end());
        string word;
        for(int i=0;i<search.size();i++)
        {
            int cnt=0;
            word+=search[i];
            vector<string> v;
            auto start = lower_bound(temp.begin(),temp.end(),word);
            for(int i=0;i<3 and (start+i)!=temp.end();i++)
            {
                string s=*(start+i);
                if(s.find(word))
                {
                    break;
                }
                v.push_back(s);
            }
            ans.push_back(v);
        }
        return ans;
    }
};