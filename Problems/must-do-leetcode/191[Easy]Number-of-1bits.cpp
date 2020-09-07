class Solution {
public:
    // note : checking each bit, two result : either true or false
    // by n &= n-1; two benefits : 
    // 1) retain upper bits and lowest bit of n be dropped
    // 2) check current bit with minimum checking
    int hammingWeight(uint32_t n) {
        int output = 0;
        while(n) {
            n &= n - 1;
            output++;
        }
        
        return output;
    }
};