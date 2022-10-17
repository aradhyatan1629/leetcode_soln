class Solution {
public:
    bool checkIfPangram(string sentence) {
        vector<int> v(26,0);
        for(int i=0;i<sentence.size();i++)
        {
            v[sentence[i]-'a']=1;
        }
        for(auto x:v)
        {
            if(x==0)
            {
                return false;
            }
        }
        return true;
    }
};