class Solution {
public:
    int largestRectangleAreaWorker(vector<int>& heights, int lo, int hi) {
        // base case
        if (lo == hi)
            return heights[lo];
        
        int mid = (lo + hi) / 2;
        int left = mid;
        int right = mid + 1;

        int maxHeightCross = 0;
        int minH = INT_MAX;
        while (true) {
            minH = min({minH, heights[left], heights[right]});
            maxHeightCross = max(maxHeightCross, minH * (right - left + 1));
            if (left == lo && right == hi)
                break;
            
            if (left == lo) {
                ++right;
                continue;
            }
                
            if (right == hi) {
                --left;
                continue;
            }

            if (heights[left - 1] >= heights[right + 1]) {
                --left;
            } else {
                ++right;
            }
        }

        return max({largestRectangleAreaWorker(heights, lo, mid),
                   largestRectangleAreaWorker(heights, mid + 1, hi),
                   maxHeightCross});
    }
    int largestRectangleArea(vector<int>& heights) {    
        return largestRectangleAreaWorker(heights, 0, heights.size() - 1);
    }
};
