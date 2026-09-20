class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        
        res[0] = 0; // base case
        for (int i = 1; i <= n; ++i) {
            res[i] = 1 + res[i & (i - 1)];
        }

        return res;
    }
};
