class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int subSum = 0;
        int totalMaxSum = -INT_MAX;
        
        for(int i = 0; i < nums.size(); i++) {
            // as long as subSum remains positive, allowable to add to totalMaxSum
            subSum += nums[i];
            totalMaxSum = max(totalMaxSum, subSum);
            subSum = max(subSum, 0);
        }
        
        return totalMaxSum;
    }
};