class Solution {
public:
    // note : 1) 16 bits shift >> | 16 bits shift << 
    //      : 2) 8 bits shift >> | 8 bits shift <<  & ff00ff00 00ff00ff
    //      : 3) 4 bits shift >> | 4 bits shift <<  & f0f0f0f0 0f0f0f0f
    //      : 4) 2 bits shift >> | 2 bits shift <<  & cccccccc 33333333
    //      : 5) 1 bit shift >> | 1 bit shift <<    & aaaaaaaa 55555555
    uint32_t reverseBits(uint32_t n) {
        n = n >> 16 | n << 16;
        n = (n & 0xff00ff00) >> 8 | (n & 0x00ff00ff) << 8;
        n = (n & 0xf0f0f0f0) >> 4 | (n & 0x0f0f0f0f) << 4;
        n = (n & 0xcccccccc) >> 2 | (n & 0x33333333) << 2;
        n = (n & 0xaaaaaaaa) >> 1 | (n & 0x55555555) << 1;
        return n;
    }
};