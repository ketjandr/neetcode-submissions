class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        // trivial algorithm

        uint32_t res = 0;
        for (int i = 0; i < 32; ++i) {
            res <<= 1;
            // get the last bit
            res |= (n & 1u);
            n >>= 1;
        }

        return res;
    }
};
