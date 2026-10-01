class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // sort intervals by their start val in interval
        sort(intervals.begin(), intervals.end(),
            [](const vector<int> &a, const vector<int> &b) {
                return a[0] < b[0];
            });
        
        vector<vector<int>> mergedIntervals;

        for (int i = 0; i < intervals.size(); ++i) {
            // empty case
            if (mergedIntervals.empty()) {
                mergedIntervals.push_back(intervals[i]);
                continue;
            }

            // compare [a0, a1] vs [b0, b1]
            int a1 = mergedIntervals.back()[1];
            int b0 = intervals[i][0];
            int b1 = intervals[i][1];
            // mergeable case, update old interval
            if (a1 >= b0) {
                mergedIntervals.back()[1] = max(a1, b1);
                continue;
            }

            // unmergeable case, push new interval
            mergedIntervals.push_back(intervals[i]);
        }

        return mergedIntervals;
    }
};
