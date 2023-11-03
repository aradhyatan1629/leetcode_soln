class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> ans;
        int i=0;
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(target[i] == j)
            {
                ans.push_back("Push");
                i++;
                cnt++;
            }
            else if(target[i] != j)
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
            if(cnt==target.size()){break;}
        }
        return ans;
    }
};

