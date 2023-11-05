class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        if(k>=arr.size())
        {
            return *max_element(arr.begin(),arr.end());
        }
        unordered_map<int,int> m;
        queue<int> q;
        for(auto x:arr)
        {
            q.push(x);
        }
        
        int first = q.front();
        q.pop();
        while(true)
        {
            int second = q.front();
            if(first>second)
            {
                m[first]++;
                q.pop();
                q.push(second);
            }
            else
            {
                q.push(first);
                first = q.front();
                m[first]++;
                q.pop();
            }
            if(m[first]==k)
            {
                break;
            }
        }
        return first;
    }
};