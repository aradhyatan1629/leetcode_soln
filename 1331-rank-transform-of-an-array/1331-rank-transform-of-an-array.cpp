class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        map<int,int> m;
        for(int i=0;i<arr.size();i++){
            m[arr[i]] = 1;
        }
        int r = 1;
        for(auto x:m){
            m[x.first] = r;
            r++;
        }
        for(int i=0;i<arr.size();i++){
            arr[i] = m[arr[i]];
        }
        return arr;
    }
};

