class Solution {
public:
    void print(vector<int> a)
    {
        for(auto x:a)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    vector<int> pancakeSort(vector<int>& arr) {
        priority_queue<int> q;
        vector<int> ans;
        vector<int> temp(arr.begin(),arr.end());
        sort(temp.begin(),temp.end());
        if(arr==temp)
        {
            return {};
        }
        for(auto x:arr)
        {
            q.push(x);
        }
        int n=arr.size();
        for(int i=n;i>=1;i--)
        {
            for(int j=0;j<n;++j)
            {
                if(arr[j]==q.top())
                {
                    int k=j+1;
                    reverse(arr.begin(),arr.begin()+k);
                    ans.push_back(k);
                    reverse(arr.begin(),arr.begin()+i);
                    ans.push_back(i);
                    q.pop();
                    if(q.empty())
                    {
                        break;
                    }
                    // cout<<"size: "<<q.size()<<" ";
                    // print(ans);
                    break;
                }
            }
            if(q.empty())
            {
                break;
            }
        }
        return ans;
    }
};