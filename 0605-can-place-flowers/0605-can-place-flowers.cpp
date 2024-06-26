class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        if(n==0)
        {
            return true;
        }
        if(flowerbed.size()==1)
        {
            if(n>1)
            {
                return false;
            }
            if(n==1 and flowerbed[0]==0)
            {
                return true;
            }
            return false;
        }
        for(int i=0;i<flowerbed.size();i++)
        {
            if(i==0 and (flowerbed[i]==0 and flowerbed.size()>1))
            {
                if(flowerbed[i+1]==0)
                {
                    flowerbed[i]=1;
                    n--;
                }
            }
            else if(i==flowerbed.size()-1 and (flowerbed[i]==0 and flowerbed.size()>1))
            {
                if(flowerbed[i-1]==0)
                {
                    flowerbed[i]=1;
                    n--;
                }
            }
            else if(flowerbed[i]==0 and flowerbed[i-1]==0 and flowerbed[i+1]==0)
            {
                flowerbed[i]=1;
                n--;
            }
            if(n==0)
            {
                return true;
            }
        }
        return false;
    }
};