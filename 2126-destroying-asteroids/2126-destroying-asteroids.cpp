class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& a) {
        sort(a.begin(),a.end());
        long long s=mass;
        for(int i=0;i<a.size();i++)
        {
            if(s>=a[i])
            {
                s+=a[i];
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};