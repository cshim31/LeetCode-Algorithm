class Solution {
public:
    // note : save boundary range of each end (left and right)
    // case 1 : none of consecutive : m[i] = 1;
    // case 2:  only m[i + 1] has been seen : m[i] = m[i + m[i + 1]] = m[i + 1] + 1
    // case 3:  only m[i - 1] has been seen : m[i] = m[i - m[i - 1]] = m[i - 1] + 1
    // case 4:  Both m[i + 1] and m[i - 1] have been seen : m[i - m[i - 1]] = m[i + m[i + 1]] = m[i - 1] + m[i + 1] + 1;
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> m;
        int output = 0;
        for(int i : nums) {
            if(m[i]) continue;
            output = max(output, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
        }
        return output;
    }
};