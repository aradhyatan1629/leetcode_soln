class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int index;
        long long sum = 0;
        for(int i=0;i<chalk.size();i++)
            sum += chalk[i];
        
        while(k>=sum)
        {
            k-=sum;
        }
        for(int i=0;i<chalk.size();i++)
        {
            if(k<chalk[i])
            {
                index=i;
                break;
            }
            k-=chalk[i];
        }
        return index;
    }
};

