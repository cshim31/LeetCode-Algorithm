class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int i;
        int fromBegin = 1;
        int fromLast = 1;
        int size = nums.size();
        
        vector<int> output(size, 1);
        
        for(i = 0; i < nums.size(); i++) {
            output[i] *= fromBegin;
            fromBegin *= nums[i];
            output[size - 1 - i] *= fromLast;
            fromLast *= nums[size - 1 - i];
        }
        
        return output;
    }
};