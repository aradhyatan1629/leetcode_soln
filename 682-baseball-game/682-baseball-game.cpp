class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> v;
        for(int i=0;i<ops.size();i++)
        {
            if(ops[i][0]=='C')
            {
                v.pop_back();
            }
            else if(ops[i][0]=='D')
            {
                int x = *(v.end()-1);
                v.push_back(x*2);
            }
            else if(ops[i][0]=='+')
            {
                int a = *((v.end()-1));
                int b = *((v.end()-2));
                v.push_back(a+b);
            }
            else
            {
                v.push_back(stoi(ops[i]));
            }
        }
        return accumulate(v.begin(),v.end(),0);
    }
};