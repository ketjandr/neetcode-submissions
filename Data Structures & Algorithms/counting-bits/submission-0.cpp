class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n + 1);
        int currPowerOf2 = 1;
        
        for (int i = 0; i <= n; ++i) {
            if (i <= 1) {
                res[i] = i;
                continue;
            }

            if (i == 2 * currPowerOf2)
                currPowerOf2 = i;
            
            res[i] = 1 + res[i - currPowerOf2];
        }

        return res;
    }
};
