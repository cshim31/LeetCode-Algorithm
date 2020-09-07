class Solution {
public:
    // note : once number reduced, meaning lowest
    int findMin(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        int mid = (l + r) / 2;
        
        while(l < r) {
            if(nums[l] < nums[r]) return nums[l];
            if(nums[l] <= nums[mid]) {
                l = mid + 1;
            }
            else {
                r = mid;
            }
            mid = (l + r) / 2;
        }
        return nums[l];
    }
};