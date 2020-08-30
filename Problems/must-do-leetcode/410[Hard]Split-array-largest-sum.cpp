class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int ans = 0;
        
        // estimate maximum value k by binary search performance
        // since maximum value = 10^6 * 1000, start from i = 30, 2^30 == 10^9
        for(int i = 30; i >= 0; i--) {
            int temp = ans | (1 << i);
            // if valid, increment ans
            // if invalid, decrement ans
            if(validate(temp, nums, m)) {
                ans = temp;
            }
        }
        
        return ans;
    }
    
    bool validate(int val, vector<int>& nums, int target) {
        int i = 0;
        int size = nums.size();
        int num_partition = 0;
        int sum = 0;
        while(i < size) {
            num_partition++;
            
            sum = 0;
            while(i < size && (sum += nums[i]) < val) {
                i++;
            }
            
            // number of partition that sums to val exceeds the required number of partition
            // meaning we have to increment value to get target number of partition that each partition exceeds value
            if(num_partition >= target) {
                if(sum < val) return false;
                return true;
            }
        }
        
        // number of partition that sums to val does not exceed the required number of partition
        // meaning we have to decrement value to make sure target number of partition that each partition exceeds value
        return false;
    }
};