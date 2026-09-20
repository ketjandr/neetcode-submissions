class Solution {
public:
    int hammingWeight(uint32_t n) {
        // see if b & 1 == 1
        int count = 0;
        while (n != 0) {
            n &= (n - 1);
            ++count;
        }
        return count;
    }
};
