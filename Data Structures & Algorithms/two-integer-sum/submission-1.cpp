class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); ++i) {
            mp[nums[i]] = i;
        }

        for (int j = 0; j < nums.size(); ++j) {
            int comp = target - nums[j];
            if (mp.contains(comp) && j != mp[comp])
                return {j, mp[comp]};
        }

        return {};
    }
};
