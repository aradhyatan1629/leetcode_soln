class Bank {
public:
    vector<long long> v;
    int n;
    Bank(vector<long long>& balance) {
        v=balance;
        n=v.size();
    }
    
    bool transfer(int account1, int account2, long long money) {
        if((account1>=1 and account1<=n) and (account2>=1 and account2<=n))
        {
            if(v[account1-1]>=money)
            {
                v[account1-1]-=money;
                v[account2-1]+=money;
                return true;
            }
        }
        return false;
    }
    
    bool deposit(int account, long long money) {
        if(account>=1 and account<=n)
        {
            v[account-1]+=money;
            return true;
        }
        return false;
    }
    
    bool withdraw(int account, long long money) {
        if(account>=1 and account<=n)
        {
            if(v[account-1]>=money)
            {
                 v[account-1]-=money;
                 return true;
            }
        }
        return false;
    }
};

/**
 * Your Bank object will be instantiated and called as such:
 * Bank* obj = new Bank(balance);
 * bool param_1 = obj->transfer(account1,account2,money);
 * bool param_2 = obj->deposit(account,money);
 * bool param_3 = obj->withdraw(account,money);
 */