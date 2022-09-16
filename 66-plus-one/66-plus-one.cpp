class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        int flag=1;
        if(digits[n-1]!=9)
        {
            digits[n-1]+=1;
            return digits;
        }
        if(digits.size()==1)
        {
            digits.push_back(1);
            digits.push_back(0);
            digits.erase(digits.begin());
            return digits;
        }
        digits[n-1]=0;
        for(int i=n-2;i>=0;i--)
        {
            while(digits[i]==9)
            {
                digits[i]=0;
                i--;
                if(i<0)
                {
                    flag=-1;
                    break;
                }
            }
            if(flag==-1)
            {
                break;
            }
            digits[i]+=1;
            break;
        }
        if(flag==-1)
        {
            digits.insert(digits.begin(),1);
            return digits;
        }
        return digits;
    }
};


// 1 4 9 9 9