class Solution {
public:
    int minOperations(int n) {
        vector<int> v(n,0);
        int op=0;
        for(int i=0;i<v.size();i++)
        {
            v[i]=(2*i)+1;
        }
        int target=accumulate(v.begin(),v.end(),0)/v.size();
        int i=0,j=v.size()-1;
        while(i<=j)
        {
            op+=target-v[i];
            i++;
            j--;
        }
        return op;
    }
};