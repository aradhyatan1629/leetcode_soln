class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++)
            m[arr[i]]++;
        
       /* for(auto x:m)
        {
            cout<<x.first<<" "<<x.second<<endl;
        }*/
        
        for(auto x:m)
        {
            if(m[x.first] > 0)
            {
                if(x.first%2!=0 and x.second > m[x.first*2])
                {
                    return false;
                }
                else if(x.first%2==0 and x.second > (m[x.first*2] + m[x.first/2]))
                {
                    return false;
                }
                else if(x.first%2!=0)
                {
                    m[x.first*2] -= m[x.first];
                    m[x.first] = 0;
                }
                else
                {
                    int t = m[x.first];
                    if(m[x.first*2]>0)
                    {
                        m[x.first]-=m[x.first*2];
                        if(m[x.first]<=0)m[x.first]=0;
                        m[x.first*2]-=t;
                        if(m[x.first*2]<=0)m[x.first*2]=0;
                    }
                    if(m[x.first]!=0 and m[x.first/2]>0)
                    {
                        m[x.first/2]-=m[x.first];
                    }
                    m[x.first]=0;
                }
            }
        }
        return true;
    }
};



/*
 


for i=0
arr[1] = 2 * arr[0]



for i=1
arr[3] = 2 * arr[2]


for i=2
arr[5] = 2 * arr[4]










*/