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
            for(int j=0;j<temp.size();j++)
            {
                if(temp[j].substr(0,word.size())==word)
                {
                    v.push_back(temp[j]);
                    cnt++;
                    if(cnt==3)
                    {
                        break;
                    }
                }
            }
            ans.push_back(v);
        }
        return ans;
    }
};