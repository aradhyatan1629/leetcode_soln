class Solution {
public:
    int maximum69Number (int num) {
        string r = to_string(num);
        for(auto &x:r)
        {
            if(x=='6')
            {
                x='9';
                break;
            }
        }
        return stoi(r);
    }
};