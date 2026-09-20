class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 10 ^ 11 ^ 10
        int acc = 0;
        // XOR is commutative, so we can always rearrange the target number in the end to achieve 0 ^ acc == acc
        for (auto num : nums) {
            acc ^= num;
        }

        return acc;
    }
};
