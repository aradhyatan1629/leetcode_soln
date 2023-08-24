class Solution {
public:
    int minimumSum(int n, int k) {
        unordered_map<int,bool> m;
        int i=1;
        int sum = 0;
        while(m.size()!=n)
        {
            if(m.find(k-i)==m.end())
            {
                sum+=i;
                m[i] = true;
            }
            i++;
        }
        return sum;
    }
};

