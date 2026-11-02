class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int lo = 0;
        int hi = rows * cols - 1;

        while (lo <= hi) {
            int mid = (lo + hi) / 2;

            int row = mid / cols;
            int col = mid % cols;

            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                hi = mid - 1;
            else
                lo = mid + 1;

        }

        return false;
    }
};
