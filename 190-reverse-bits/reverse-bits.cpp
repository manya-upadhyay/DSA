class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            // Shift result to the left to make room for the next bit
            res <<= 1;
            // Get the last bit of n and add it to res
            res |= (n & 1);
            // Shift n to the right to process the next bit
            n >>= 1;
        }
        return res;
    }
};