class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        for(int i=1;i<=n;i++)
        {
            if(i>*(target.end()-1))
            {
                break;
            }
            if(find(target.begin(),target.end(),i)!=target.end())
            {
                ans.push_back("Push");
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};