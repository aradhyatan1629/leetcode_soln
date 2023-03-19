class BrowserHistory {
public:
    vector<string> v;
    int current=0;
    BrowserHistory(string homepage) {
        v.push_back(homepage);
    }
    
    void visit(string url) {
        v.erase(v.begin()+current+1,v.end());
        v.push_back(url);
        current++;
    }
    
    string back(int steps) {
        if(current-steps<0)
        {
            current=0;
            return v[0];
        }
        string t = v[current-steps];
        current-=steps;
        return t;
    }
    
    string forward(int steps) {
        if(current+steps>=v.size())
        {
            current=v.size()-1;
            return v[v.size()-1];
        }
        string t = v[current+steps];
        current+=steps;
        return t;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */