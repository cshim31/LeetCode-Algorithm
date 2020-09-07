class Solution {
public:
    // absolute point : regradless of current index, as long as we can maximize the distance
    // then we are guranteed to reach end
    bool canJump(vector<int>& nums) {
        int dis = nums[0];
       for(int i = 0; i <= dis; i++) {
           dis = max(dis, i + nums[i]);
           if(dis >= nums.size() - 1) return true;
       }
        
        return false;
    }
};