class Solution {
public:
    int getSum(int a, int b) {
        // sum a, b and save the carry
        while (b != 0) {
            unsigned carry = static_cast<unsigned>(a & b) << 1;
            a ^= b;
            b = static_cast<int>(carry);
        }

        return a;
    }
};
