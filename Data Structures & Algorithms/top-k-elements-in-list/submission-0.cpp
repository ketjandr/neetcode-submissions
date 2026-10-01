class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // hashmap to count frequency
        unordered_map<int, int> freq;

        for (auto &num : nums) {
            if (freq.contains(num))
                freq[num] += 1;
            else
                freq[num] = 1;
        }

        priority_queue<pair<int, int>> pq; //max heap

        // heapify O(n)
        for (const auto& [key, value] : freq) {
            pq.push(make_pair(value, key));
        }

        // pop k elements for the prioirty queue
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            int key = pq.top().second;
            pq.pop();
            res.push_back(key);
        }

        return res;
    }
};
