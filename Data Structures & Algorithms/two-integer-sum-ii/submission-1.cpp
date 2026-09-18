class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0; // left ptr
        int j = numbers.size() - 1; // right ptr

        // &numbers is sorted, so we can use 2 pointer approach
        while (i < j) {
            int x = numbers[i];
            int y = numbers[j];

            // check if numbers[i] + numbers[j] == target
            if (x + y == target)
                return {i + 1, j + 1};
            
            // check if x + y < target
            if (x + y < target) {
                i++;
            } else j--; // then x + y > target
        }

        // ret [i, j] s.t. i + j == target, i < j
        return {};
    }
};
