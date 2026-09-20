class Solution {
public:
    int hammingWeight(uint32_t n) {
        // see if b & 1 == 1
        int count = 0;
        for (uint32_t i = 0; i < 32; ++i) {
            // take the last bit (mask with 1)
            if (n & 1 == 1)
                count++;
            
            // do LSR
            n >>= 1;
        }

        return count;
    }
};
