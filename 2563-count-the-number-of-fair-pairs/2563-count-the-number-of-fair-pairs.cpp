class Solution {
public:
    int searchLow(int lower, int i, vector<int>& nums) {
        int low = i + 1;  // We need j > i
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[i] + nums[mid] >= lower) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return low;  // Return the index where the sum is >= lower
    }

    int searchHigh(int upper, int i, vector<int>& nums) {
        int low = i + 1;  // We need j > i
        int high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[i] + nums[mid] <= upper) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return high;  // Return the index where the sum is <= upper
    }

    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n == 1) return 0;

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int indLow = searchLow(lower, i, nums);
            int indHigh = searchHigh(upper, i, nums);

             if (indLow <= indHigh) {
                ans += (indHigh - indLow + 1);
            }
        }

        return ans;
    }
};
