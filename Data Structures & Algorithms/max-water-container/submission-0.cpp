class Solution {
public:
    int maxArea(vector<int>& heights) {
        // greedy choice: move pointer with less current height
        int i = 0;
        int j = heights.size() - 1;

        int best = 0;
        while (i < j) {
            int area = min(heights[i], heights[j]) * (j - i);
            best = max(best, area);

            if (heights[i] >= heights[j])
                j--;
            else
                i++;
        }
        
        return best;
    }
};
