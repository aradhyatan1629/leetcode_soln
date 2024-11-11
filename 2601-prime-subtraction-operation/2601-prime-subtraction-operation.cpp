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
        int low = 0;
        int high = v.size()-1;
        int ans = -1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            if(v[mid] < x){
                if(x-v[mid] < y){
                    ans = v[mid];
                    high = mid-1;
                }
                else
                    low = mid+1;
            }
            else{
                high = mid-1;
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