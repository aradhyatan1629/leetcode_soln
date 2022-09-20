class MapSum {
public:
    unordered_map<string,int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key]=val;
    }
    
    int sum(string prefix) {
        int sz=prefix.size();
        int sum=0;
        for(auto x:m)
        {
            if(x.first.substr(0,sz)==prefix)
            {
                sum+=x.second;
            }
        }
        return sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */