class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n=people.size();
        int i=0,j=n-1;
        int cnt=0;
        sort(people.begin(),people.end());
        while(i<=j)
        {
            if(people[i]+people[j]<=limit)
            {
                cnt++;
                i++;
                j--;
            }
            else
            {
                j--;
                cnt++;
            }
        }
        return cnt;
    }
};

//1 2 4 5 limit=6

// 1 2 2 3
    
// 3 3 4 5