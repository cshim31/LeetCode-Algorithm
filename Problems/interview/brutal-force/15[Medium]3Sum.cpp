class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> output;
        
        // exception
        if(size < 3) return output;
        
        sort(nums.begin(), nums.end());
        
        int i = 0;
        while(i < size - 2 && nums[i] <= 0) {
            int l = i + 1;
            int r = size - 1;
            
            int sum = 0;
            
            while(l < r) {
                sum = nums[i] + nums[l] + nums[r];
                if(sum < 0) l++;
                else if(sum > 0) r--;
                
                // answer found
                else {
                    output.push_back({nums[i], nums[l], nums[r]});
                    // avoid repeating value
                    while(l < r && nums[l] == nums[l + 1]) l++;
                    while(r > l && nums[r] == nums[r - 1]) r--;
                    l++;
                    r--;
                }
            }
            // avoid repeating value
            while(i < size - 2  && nums[i] == nums[i + 1]) i++;
            i++;
        }
        
        return output;
    }
};