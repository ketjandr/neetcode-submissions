class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // [9,1,4,2,3,3,7]
        // [1,1,2,2,3,3,4]
        vector<int> lenSoFar(nums.size());
        int maxLen = 0;

        for (int i = 0; i < nums.size(); ++i) {
            int maxPrevLen = 0;
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j])
                    maxPrevLen = max(maxPrevLen, lenSoFar[j]);
            }

            lenSoFar[i] = maxPrevLen + 1;
            maxLen = max(maxLen, lenSoFar[i]);
        }

        return maxLen;
        
    }
};
