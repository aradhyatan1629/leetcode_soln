class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int i=0,j=0,dist=0;
        int temp=0,temp1=0;
        for(i=0;i<colors.size();i++)
        {
            temp1=0;
            for(j=0;j<colors.size();j++)
            {
                if(colors[i]!=colors[j])
                {
                    temp=abs(i-j);
                    if(temp>temp1)
                    {
                        temp1=temp;
                    }
                }
            }
            if(temp1>dist)
            {
                dist=temp;
            }
        }
        return dist;
    }
};