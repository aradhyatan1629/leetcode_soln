//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> asteroidCollision(int N, vector<int> &asteroids) {
        stack<int> st;
        for(int i=0;i<asteroids.size();i++)
        {
            if(st.empty() or asteroids[i]>0)
            {
                st.push(asteroids[i]);
            }
            else
            {
                while(!st.empty() and (st.top()>0 and st.top()<abs(asteroids[i])))
                {
                    st.pop();
                }
                if(st.empty() or st.top()<0)
                {
                    st.push(asteroids[i]);
                }
                else if(!st.empty() and st.top()==abs(asteroids[i]))
                {
                    st.pop();
                }
            }
        }
        vector<int> ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> asteroids(N);
        for (int i = 0; i < N; i++) cin >> asteroids[i];

        Solution obj;
        vector<int> ans = obj.asteroidCollision(N, asteroids);
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends