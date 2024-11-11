class Solution {
public:
    bool isPrime(int n){
        for(int i=2;i<=sqrt(n);i++){
            if(n%i == 0)
                return false;
        }
        return true;
    }
    
    void allPrimes(vector<int> &v){
        for(int i=2;i<=1000;i++){
            if(isPrime(i))
                v.push_back(i);
        }
    }
    
    int findPrime(int x,int y,vector<int> &v){
        int ans = -1;
        for(int i=0;i<v.size();i++){
            if(v[i] < x && x-v[i] < y){
                ans = v[i];
                break;
            }
        }
        return ans;
    }
    
    bool primeSubOperation(vector<int>& nums) {
        int n = nums.size();
        vector<int> v;
        allPrimes(v);

        for(int i=n-2;i>=0;i--){
            if(nums[i] >= nums[i+1]){
                int prime = findPrime(nums[i],nums[i+1],v);
                if(prime == -1 || nums[i]-prime >= nums[i+1]){
                    // cout<<i<<" "<<prime<<endl;
                    return false;
                }
                    
                nums[i] -= prime;
            }
        }
        return true;
    }
};